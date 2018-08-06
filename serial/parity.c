#include "defs.h"

static char xor_bits(char byte) {
    char xor, bit;
    // For all the bits in the given byte...
    for (bit = 1, xor = 0; bit <= BYTE_SIZE; ++bit) {
        // Inspect the (current) LSB
        xor ^= byte & 1;

        // Shift right to always check the LSB
        byte >>= 1;
    }
    // Will return 1 if number of bits in the byte is odd as XOR operation does
    return xor;
}

void set_parity_bit(char* byte, parity parity_) {
    // Will get 1 in 'xor' if number of bits in the byte is odd
    char xor = xor_bits(*byte);

    // Check mismatch between XOR of bits and expected parity, then adjust properly
    if (even == parity_ && 1 == xor || odd == parity_ && 0 == xor) {
        *byte |= PARITY_BIT;
    } else {
        *byte &= ~PARITY_BIT;
    }
}

bool check_parity_bit(const char* byte, parity parity_) {
    // Will get 1 in 'xor' if number of bits in the byte is odd
    char xor = xor_bits(*byte);

    // Check match between XOR result and expected parity
    return even == parity_ && 0 == xor || odd == parity_ && 1 == xor;
}
