#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "defs.h"

static unsigned int pack(char byte) {
    unsigned int frame = 0, bit = BIT0;
    unsigned char original = byte;
    while (bit <= BIT7) {
        frame = (frame << 1) | (byte & 1);
        byte >>= 1, bit <<= 1;
    }
    frame = (frame << 2) | STOP_BITS;
    if (debug) printf("Packed %02x into frame %03x.\n", original, frame);
    return frame;   // Return 32-bits frame containing 0dddddddp11 with stop-bits in LSBs
}

static void progress_bar(int progress) {
    if (debug) {
        return;
    }
    printf("\r" SIMUL_FILE " 0%% [");
    size_t hashes = progress / 5;
    size_t blanks = 20 - hashes;
    while (hashes > 0) {
        putchar('#');
        --hashes;
    }
    while (blanks > 0) {
        putchar(' ');
        --blanks;
    }
    printf("] 100%%");
    fflush(stdout);
}

static char unpack(unsigned int frame) {
    char byte = 0;
    int bit = BIT7, original = frame;
    frame >>= 2;                                // Discards stop-bits
    while (bit >= BIT0) {
        byte = (byte << 1) | (frame & 1);
        frame >>= 1, bit >>= 1; 
    }
    if (debug) printf("Unpacked %03x into byte %02x.\n", original, (unsigned char) byte);
    return byte;
}

static void send_byte(FILE* f, char b, size_t t, size_t* n) {
    if (EOF == fputc(b, f)) {
        perror("(Serializing) File operation error");
        exit(EXIT_FAILURE);
    }
    if (debug) printf("Sent byte %02x.\n", (unsigned char) b);
    ++(*n);
    float progress = *n * FRAME_SIZE * 100.0 / (t * FRAME_SIZE);
    if (0 == (int) progress % 5) {
        progress_bar(progress);
    }
}

void serialize(FILE* tmparq, parity parity_, int baud) {
    // Create data.ser file
    if (debug) puts("Now serializing to " SIMUL_FILE "...");
    FILE* serial = fopen(SIMUL_FILE, "wb");
    if (NULL == serial) {
        perror("(Serializing) File operation error");
        exit(EXIT_FAILURE);
    }
    // Get streamed, temporary file size to calculate progress bar
    fseek(tmparq, 0, SEEK_END);
    size_t size = ftell(tmparq) * FRAME_SIZE / BYTE_SIZE;

    // Time to wait between two bytes to simulate transmission speed
    useconds_t delay = BYTE_SIZE * 1000000 / baud;

    // Start reading from beginning of temporary file
    fseek(tmparq, 0, SEEK_SET);

    size_t counter = 0;
    while (!feof(tmparq)) {
        static unsigned int saved = 0;  // bits saved for next round
        static size_t nsaved = 0;       // number of saved bits for next round

        // Read new byte from file
        char b = fgetc(tmparq);
        if (EOF == b) {
            if (ferror(tmparq)) {
                perror("(Serializing) File operation error");
                exit(EXIT_FAILURE);
            } else {
                // Are there pending bits to be "transmitted" before finishing with
                // serialization?
                if (0 < nsaved) {
                    usleep(delay);
                    send_byte(serial, saved << (BYTE_SIZE - nsaved), size, &counter);
                }
            }
        } else {
            if (debug) printf("Got byte %02x from stream.\n", (unsigned char) b);
            // Set parity bit if necessary at the new byte
            if (none != parity_) {
                set_parity_bit(&b, parity_);
            }
            // Compound saved bits with new frame
            unsigned int window = (saved << FRAME_SIZE) | pack(b);
            size_t total = nsaved + FRAME_SIZE;
            nsaved = total - BYTE_SIZE;

            // Send the actual 8 most significant bits
            usleep(delay);
            send_byte(serial, window >> nsaved, size, &counter);

            // Save the pending bits that remained in the less significant bits
            size_t to_shift = sizeof(window)*BYTE_SIZE - nsaved;
            saved = (window << to_shift) >> to_shift;

            // Is there a whole byte to be "sent" in pending buffer?
            while (BYTE_SIZE <= nsaved) {
                to_shift = nsaved - BYTE_SIZE;
                usleep(delay);
                send_byte(serial, saved >> to_shift, size, &counter);
                nsaved -= BYTE_SIZE;
                saved = (saved << to_shift) >> to_shift;
            }
        }
    }
    progress_bar(100);
    if (!debug) puts(" Done!");

    fclose(tmparq);
    fclose(serial);
    if (debug) puts("End of transmission.\n");
}

FILE* deserialize(parity parity_, int baud) {
    // Create temporary file to get the complete stream of deserialized bytes
    FILE* tmp;
    if (debug) {
        puts("\nStarting reception: deserializing bytes to " DEBUG_FILE "...");
        tmp = fopen(DEBUG_FILE, "w+b");
    } else {
        tmp = tmpfile();
    }
    if (NULL == tmp) {
        goto FAIL;
    }
    // Open data.ser file
    if (debug) puts("Opening " SIMUL_FILE "...");
    FILE* serial = fopen(SIMUL_FILE, "rb");
    if (NULL == serial) {
        goto FAIL;
    }
    // Get file size to calculate progress bar
    fseek(serial, 0, SEEK_END);
    size_t size = ftell(serial);

    // Time to wait between two bytes to simulate reception speed
    useconds_t delay = BYTE_SIZE * 1000000 / baud;

    // Start reading from beginning of data.ser file
    fseek(serial, 0, SEEK_SET);

    size_t counter = 0;
    while (!feof(serial)) {
        static unsigned int saved = 0;  // bits saved for next round
        static size_t nsaved = 0;       // number of saved bits for next round

        // Receive new byte
        usleep(delay);
        char b = fgetc(serial);
        if (EOF == b) {
            if (ferror(serial)) {
                goto FAIL;
            }
        } else {
            if (debug) printf("Received byte %02x.\n", (unsigned char) b);

            // Compound buffered bits with new byte
            saved = (saved << BYTE_SIZE) | (unsigned char) b;
            nsaved += BYTE_SIZE;

            // Check for a complete frame
            if (FRAME_SIZE > nsaved) {
                continue;
            }
            // Retrieve byte from frame
            char byte = unpack(saved >> (nsaved - FRAME_SIZE));

            // Check the parity, if applicable
            if (none != parity_ && !check_parity_bit(&byte, parity_)) {
                fprintf(stderr, "\nParity error detected.\n");
                exit(EXIT_FAILURE);
            }
            // Clear parity bit
            byte &= ~PARITY_BIT;

            // Write it to file
            if (EOF == fputc(byte, tmp)) {
                goto FAIL;
            }
            if (debug) printf("Put byte %02x to stream.\n", (unsigned char) byte);
            ++counter;
            float progress = counter * 100 / size;
            if (0 == (int) progress % 5) {
                progress_bar(progress);
            }
            // Save the pending bits that remained in the less significant bits
            nsaved -= FRAME_SIZE;
            size_t to_shift = sizeof(saved)*BYTE_SIZE - nsaved;
            saved = (saved << to_shift) >> to_shift;
        }
    }
    progress_bar(100);
    if (!debug) puts(" Done!");

    fclose(serial);
    return tmp;
FAIL:
    perror("\n(Deserializing) File operation error");
    exit(EXIT_FAILURE);
}
