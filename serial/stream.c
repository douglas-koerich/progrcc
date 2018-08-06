#include <stdlib.h>
#include <stdio.h>
#include "defs.h"

FILE* streamize(int arqc, char* arqv[]) {
    // Create temporary file to get the complete stream of bytes from all files
    FILE* tmp;
    if (debug) {
        puts("\nStarting transmission: streaming bytes to " DEBUG_FILE "...");
        tmp = fopen(DEBUG_FILE, "w+b");
    } else {
        tmp = tmpfile();
    }
    if (NULL == tmp) {
        goto FAIL;
    }
    // Start the complete stream with SOH as specified in documentation
    if (EOF == fputc(SOH, tmp)) {
        goto FAIL;
    }
    int a;
    // For every file in the argument list...
    for (a = 0; a < arqc; ++a) {
        // Open the file for reading
        if (debug) printf("Opening file %s...\n", arqv[a]);
        FILE* arq = fopen(arqv[a], "rb");
        if (NULL == arq) {
            goto FAIL;
        }
        // Add STX to indicate start of new file as specified in documentation
        if (EOF == fputc(STX, tmp)) {
            goto FAIL;
        }
        // Until the end of file...
        if (debug) printf("Contents (hexa): ");
        while (!feof(arq)) {
            char b = fgetc(arq);
            if (EOF == b) {
                if (ferror(arq)) {
                    goto FAIL;
                }
            } else {
                // Write the taken byte into temporary file
                if (debug) printf("%02x ", b);
                if (EOF == fputc(b, tmp)) {
                    goto FAIL;
                }
                // If taken byte is one of the special marks, duplicate it in the
                // temporary file, as specified in documentation
                if (SOH == b || STX == b || ETX == b || EOT == b) {
                    if (EOF == fputc(b, tmp)) {
                        goto FAIL;
                    }
                }
            }
        }
        // Once it is done with the file, add ETX to indicate its end
        if (debug) printf("\nFinished with file %s.\n", arqv[a]);
        fclose(arq);
        if (EOF == fputc(ETX, tmp)) {
            goto FAIL;
        }
    }
    // After all files were processed, finish the stream with EOT as specified in documentation
    if (EOF == fputc(EOT, tmp)) {
        goto FAIL;
    }
    if (debug) puts("End of streaming.");
    return tmp;
FAIL:
    perror("\n(Streaming) File operation error");
    exit(EXIT_FAILURE);
}

static FILE* create_next_file(void) {
    static int filenum = 1;
    char filename[] = "data.n";
    snprintf(filename, sizeof(filename), "data.%d", filenum++);
    if (debug) printf("Creating new file %s...\nContents (hexa): ", filename);
    return fopen(filename, "wb");
}

void destreamize(FILE* tmparq) {
    // Return file pointer to begin of file (last position was end after finished to write)
    fseek(tmparq, 0, SEEK_SET);

    // Use a FSM to control the special handling of marks in the temporary file
    state st = idle;

    if (debug) puts("\nReading stream of deserialized bytes:");
    char mark;
    FILE* arq;

    // Until the end of temporary file (stream of bytes taken from deserialization)
    while (!feof(tmparq)) {
        char b = fgetc(tmparq);
        if (EOF == b) {
            if (ferror(tmparq)) {
                goto FAIL;
            } else if (finished != st) {
                // Return failure if end of file was reached without the proper indication
                goto BAD;
            }
        } else switch (st) {
            case idle:
                // When in idle state this should be the first byte and should be SOH
                if (SOH != b) {
                    goto BAD;
                }
                // Ok, let's starting the stream!
                st = started;
                break;
            case started:
                // When starting the stream, should read the indication of a new file
                if (STX != b) {
                    goto BAD;
                }
                // Create next (first!) file
                arq = create_next_file();
                if (NULL == arq) {
                    goto FAIL;
                }
                // File created, starting with it!
                st = file_begin;
                break;
            case file_begin:
            case read_byte:
                // One more byte read, check if a special one
                if (SOH == b || STX == b || ETX == b || EOT == b) {
                    // We cannot decide if it is indeed an indication or a regular byte
                    // in the stream, we have to wait for next one
                    mark = b;
                    st = read_mark;
                // Write normally if it is not a special one
                } else if (EOF == fputc(b, arq)) {
                    goto FAIL;
                } else {
                    if (debug) printf("%02x ", b);
                    // We are currently reading bytes...
                    st = read_byte;
                }
                break;
            case read_mark:
                // Last byte was a mark, check if it is being repeated
                if (mark == b) {
                    // Since it was repeated, it has to be stored in output file
                    if (EOF == fputc(b, arq)) {
                        goto FAIL;
                    }
                    if (debug) printf("%02x ", b);
                    // So, this was indeed a regular byte reading...
                    st = read_byte;
                // No, it is another byte different from the mark previously read
                } else if (ETX != mark) {
                    // Since we've been reading bytes, the only expected mark
                    // received before was ETX
                    goto BAD;
                } else {
                    if (debug) puts("\nFinished with this file.");
                    fclose(arq);
                    st = file_end;
                    // Once we closed the previous file, there is only two possibilities:
                    switch (b) {
                        // (a) We are starting new file
                        case STX:
                            arq = create_next_file();
                            if (NULL == arq) {
                                goto FAIL;
                            }
                            st = file_begin;
                            break;
                        // (b) That was the last file, now closing the stream
                        case EOT:
                            st = finished;
                            break;
                        default:
                            goto BAD;
                    }
                }
                break;
            case file_end:
            case finished:
                // No additional bytes should be read in these states
                goto BAD;
        }
    }
    if (debug) puts("End of reception.\n");
    fclose(tmparq);
    return;
BAD:
    fprintf(stderr, "\nUnexpected file contents.\n");
    exit(EXIT_FAILURE);
FAIL:
    perror("\n(Destreaming) File operation error");
    exit(EXIT_FAILURE);
}
