#ifndef BIGSTRUCT_H
#define BIGSTRUCT_H

#define NUM_INTS 150
#define NUM_DOUB 30

struct big {
    char string[2048];
    int vetor_i[NUM_INTS];
    double vetor_d[NUM_DOUB];
};
typedef struct big Big;

#endif // BIGSTRUCT_H

