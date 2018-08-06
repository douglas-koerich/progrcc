#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdbool.h>

extern bool debug;

#define SIMUL_FILE  "data.ser"
#define DEBUG_FILE  "debug.bin"
#define SOH         0x1
#define STX         0x2
#define ETX         0x3
#define EOT         0x4
#define BYTE_SIZE   8
#define FRAME_SIZE  11
#define BIT7        0x80
#define BIT0        0x1
#define PARITY_BIT  BIT7
#define STOP_BITS   0x3

enum direction {
    unk,
    tx,
    rx
};
typedef enum direction direction;

enum parity {
    none,
    odd,
    even
};
typedef enum parity parity;

enum state {
    idle,
    started,
    file_begin,
    read_byte,
    read_mark,
    file_end,
    finished
};
typedef enum state state;

FILE* streamize(int arqc, char* arqv[]);
void serialize(FILE* tmparq, parity parity_, int baud);
FILE* deserialize(parity parity_, int baud);
void destreamize(FILE* tmparq);
void set_parity_bit(char* byte, parity parity_);
bool check_parity_bit(const char* byte, parity parity_);

#endif // DEFS_H
