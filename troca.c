#include <stdlib.h>
#include <stdio.h>

void troca(int*, int*);

int main(void) {
    int A = 10, B = 15;

    printf("A = %d, B = %d.\n", A, B);
    troca(&A, &B);
    printf("A = %d, B = %d.\n", A, B);

    return EXIT_SUCCESS;
}

void troca(int* a, int* b) {
    /* Algoritmo CLASSICO de troca:
    int c;
    c = *b;
    *b = *a;
    *a = c;
    */

    *a += *b;
    *b = *a - *b;
    *a -= *b;
}
