#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

void troca_vetores(char[*], char[*], size_t);

#define TAM_VETOR 20

int main(void) {
    srand((unsigned) time(0));

    char vetor_A[TAM_VETOR], vetor_B[TAM_VETOR];

    int i;
    for (i=0; i<TAM_VETOR; ++i) {
        do {
            vetor_A[i] = rand() % 128;  // dentro da faixa de caracteres ASCII
        } while (!isupper(vetor_A[i]) && !isdigit(vetor_A[i]));
        do {
            vetor_B[i] = rand() % 128;
        } while (!isupper(vetor_B[i]) && !isdigit(vetor_B[i]));
    }

    printf("*** ANTES DA TROCA ***\nVetor A: ");

    for (i=0; i<TAM_VETOR; ++i) {
        printf("%c ", vetor_A[i]);
    }
    printf("\nVetor B: ");
    for (i=0; i<TAM_VETOR; ++i) {
        printf("%c ", vetor_B[i]);
    }
    printf("\n");

    // int a, b;
    // for (a=0, b=TAM_VETOR-1; a<TAM_VETOR; ++a, --b) {
    //     char aux = vetor_A[a];
    //     vetor_A[a] = vetor_B[b];
    //     vetor_B[b] = aux;
    // }
    troca_vetores(vetor_A, vetor_B, TAM_VETOR);

    printf("\n*** DEPOIS DA TROCA ***\nVetor A: ");

    for (i=0; i<TAM_VETOR; ++i) {
        printf("%c ", vetor_A[i]);
    }
    printf("\nVetor B: ");
    for (i=0; i<TAM_VETOR; ++i) {
        printf("%c ", vetor_B[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

void troca_vetores(char vA[], char vB[], size_t n) {
    int a, b;
    for (a=0, b=n-1; a<n; ++a, --b) {
        char aux = vA[a];
        vA[a] = vB[b];
        vB[b] = aux;
    }
}
