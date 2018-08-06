#include <stdlib.h>
#include <stdio.h>

#define TAM_VETOR   5
#define NUM_LINHAS  3
#define NUM_COLUNAS 2

int main(void) {
    int vetor[TAM_VETOR] = { 1, 2, 3, 4, 5 };
    int matriz[NUM_LINHAS][NUM_COLUNAS] = {
        { 23, 5 },
        { -9, 4 },
        { 14, 2 }
    };
    int* p;

    int i, l, c;
    puts("Vetor:");
    for (i = 0, p = vetor; i < TAM_VETOR; ++i, ++p) {
        printf("%d ", *p);
    }

    puts("\nMatriz (em linha):");
    // Percurso em linha
    // for (l = 0, p = matriz[0]; l < NUM_LINHAS; ++l) {
    for (l = 0, p = (int*) matriz; l < NUM_LINHAS; ++l) {
        for (c = 0; c < NUM_COLUNAS; ++c, ++p) {
            // printf("%d ", matriz[l][c]);
            printf("%d ", *p);
        }
        putchar('\n');
    }

    // Percurso em coluna
    puts("Matriz (em coluna):");
    p = (int*) matriz;
    for (c = 0; c < NUM_COLUNAS; ++c) {
        for (l = 0; l < NUM_LINHAS; ++l) {
            // printf("%d ", matriz[l][c]);
            printf("%d ", *(p + l*NUM_COLUNAS + c));
            //              ^   ^ ^             ^
            //              |   | |             |
            //              |   | |             deslocamento dentro da linha (sobre colunas)
            //              |   | tamanho de uma linha inteira a saltar \_ deslocamento sobre linhas
            //              |   numero de linhas completas a saltar     /
            //              endereco/referencia de inicio da matriz
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}

