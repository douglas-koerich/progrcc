#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "defs.h"

bool debug = false;

int main(int argc, char* argv[]) {
    bool baud_ = false, bits_ = false, parity__ = false;
    int opt, baud, data_bits, index;
    parity parity_;
    direction flow = unk;

    // For all options contained in the command line...
    while (-1 != (opt = getopt(argc, argv, "ghb:d:p:"))) {
        switch (opt) {
            case 'b':
                // Tell baud-rate is present
                baud_ = true;

                // Get baud-rate value from option argument
                baud = atoi(optarg);

                // Validate baud-rate value
                if (110 != baud && 300 != baud && 1200 != baud) {
                    fprintf(stderr, "Unsupported baud-rate value %d.\n", baud);
                    return EXIT_FAILURE;
                }
                break;
            case 'd':
                // Tell number of data bits is present
                bits_ = true;

                // Get number of bits from option argument
                data_bits = atoi(optarg);

                // Validate number of bits
                if (7 != data_bits && 8 != data_bits) {
                    fprintf(stderr, "Invalid number %d for data bits.\n", data_bits);
                    return EXIT_FAILURE;
                }
                break;
            case 'p':
                // Tell parity selection is present
                parity__ = true;

                // Look at parity option
                switch (optarg[0]) {
                    case 'n':
                        parity_ = none;
                        break;
                    case 'o':
                        parity_ = odd;
                        break;
                    case 'e':
                        parity_ = even;
                        break;
                    default:
                        fprintf(stderr, "Unknown parity option '%c'.\n", optarg[0]);
                        return EXIT_FAILURE;
                }
                break;
            case 'g':
                debug = true;
                break;
            case 'h':
                // Additional (not required) option for help
                fprintf(stderr, "Use: %s tx|rx -b <baud> -d <bits> -p <parity> arq1 [arq2 ...]\n", argv[0]);
            default:
                return EXIT_FAILURE;
        }
    }
    // Check all options were given by user
    if (!baud_ || !bits_ || !parity__) {
        fprintf(stderr, "Missing options.\n");
        return EXIT_FAILURE;
    }
    // Check consistency between number of data bits and parity as specified
    if (none == parity_ && 7 == data_bits || none != parity_ && 8 == data_bits) {
        fprintf(stderr, "Inconsistent baud-rate and parity options.\n");
        return EXIT_FAILURE;
    }
    // Look for direction (TX/RX) option
    for (index = optind; index < argc; ++index) {
        if (0 == strcmp(argv[index], "tx")) {
            flow = tx;
        } else if (0 == strcmp(argv[index], "rx")) {
            flow = rx;
        }
    }
    switch (flow) {
        case tx: {
            if (argc < optind + 2) {
                fprintf(stderr, "Missing arguments.\n" );
                return EXIT_FAILURE;
            }
            // Setup the file name(s)
            int arqc = argc - optind - 1;
            char** arqv = argv + optind + 1;

            // Call the proper sequence of operations
            serialize(streamize(arqc, arqv), parity_, baud);
            break;
        }
        case rx:
            if (argc < optind + 1) {
                fprintf(stderr, "Missing argments.\n" );
                return EXIT_FAILURE;
            }
            // Call the proper sequence of operations
            destreamize(deserialize(parity_, baud));
            break;

        default:
            fprintf(stderr, "Missing or invalid direction.\n");
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
