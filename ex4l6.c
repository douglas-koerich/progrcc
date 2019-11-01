#include <stdlib.h>
#include <stdio.h>

void soma_colunas(size_t, size_t, const int [*][*], int [*]);

int main(void) {
    int linhas, colunas;

    puts("Digite as dimensoes da matriz:");
    printf("Linhas? ");
    scanf("%d", &linhas);
    printf("Colunas? ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    int l, c;
    for (l = 0; l < linhas; ++l) {
        for (c = 0; c < colunas; ++c) {
            printf("Valor de %d,%d? ", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }

    puts("Matriz digitada");
    for (l = 0; l < linhas; ++l) {
        for (c = 0; c < colunas; ++c) {
            printf("%3d ", matriz[l][c]);
        }
        putchar('\n');
    }

    int vetor_somas[colunas];

    soma_colunas(linhas, colunas, matriz, vetor_somas);

    puts("Soma das colunas");
    for (c = 0; c < colunas; ++c) {
        printf("%d ", vetor_somas[c]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

void soma_colunas(size_t N, size_t M, const int m[N][M], int v[M]) {
    int l, c;
    for (c = 0; c < M; ++c) {
        v[c] = 0;
        for (l = 0; l < N; ++l) {
            v[c] += m[l][c];
        }
    }
}

