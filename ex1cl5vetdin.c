#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAM 10

int main(int argc, char* argv[]) {
    srand((unsigned) time(NULL));

    int *X, *Y, *S; // para os "vetores" alocados dinamicamente

    X = (int*) malloc(sizeof(int) * TAM);
    int i;
    for (i=0; i<TAM;) {
        int num = rand() % 100 + 1;
        bool repetido = false;
        int j;
        for (j=i-1; j>=0; --j) {
            if (X[j] == num) {
                repetido = true;
            }
        }
        if (repetido == false) {
            X[i] = num;
            ++i;
        }
    }

    Y = (int*) malloc(sizeof(int) * TAM);
    for (i=0; i<TAM;) {
        int num = rand() % 100 + 1;
        bool repetido = false;
        int j;
        for (j=i-1; j>=0; --j) {
            if (Y[j] == num) {
                repetido = true;
            }
        }
        if (repetido == false) {
            Y[i] = num;
            ++i;
        }
    }

    S = (int*) malloc(sizeof(int) * TAM);
    for (i=0; i<TAM; ++i) {
        S[i] = X[i] + Y[i];
    }

    puts("Imprimindo a soma: ");
    for (i=0; i<TAM; ++i) {
        printf("%d+%d=%d ", X[i], Y[i], S[i]);
    }
    putchar('\n');

    free(X);
    free(Y);
    free(S);

    return EXIT_SUCCESS;
}
