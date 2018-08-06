#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 3
#define M 4

void soma_colunas(size_t, size_t, int [*][*], int[*]);

int main(void) {
    srand((unsigned) time(NULL));

    int matriz[N][M], vetor[M]; // vetor com mesma dimensao do numero de colunas
    int l, c;

    for (l=0; l<N; ++l) {
        for (c=0; c<M; ++c) {
            matriz[l][c] = rand() % 50 + 1; // numeros aleatorios entre 1 e 50
            printf("%3d ", matriz[l][c]);
        }
        putchar('\n');
    }
    soma_colunas(N, M, matriz, vetor);

    printf("As somas das colunas da matriz sao: ");
    for (c=0; c<M; ++c) {
        printf("%d ", vetor[c]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

void soma_colunas(size_t linhas, size_t colunas, int matriz[linhas][colunas],
                  int vetor[colunas]) {
    // Percurso por colunas
    int col, lin;
    for (col=0; col<colunas; ++col) {
        vetor[col] = 0;
        for (lin=0; lin<linhas; ++lin) {
            vetor[col] += matriz[lin][col];
        }
    }
}
