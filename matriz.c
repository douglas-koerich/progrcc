#include <stdlib.h>
#include <stdio.h>

/* |  2  4  7  | (0)
   | 12 -3  0  | (1)
   |  0  0  0  | (2)
   | -8 15 23  | (3)
   |  0  0  2  | (4)
    (0) (1) (2)
*/
#define LINHAS  5
#define COLUNAS 3

int maior_da_matriz(size_t, size_t, int [*][*]);

int main(void) {
    // Declaracao de uma matriz com 5 linhas e 3 colunas, nao inicializada
    int tabela[LINHAS][COLUNAS];    // nao eh [LINHAS, COLUNAS]

    // Uma outra matriz, inicializada com o exemplo anterior
    int matriz[][COLUNAS] = {
        { 2, 4, 7 },
        { 12, -3 }, // ultima coluna sem preenchimento
        [3] = { -8, 15, 23 },   // pulei a linha 2, que fica inicializada com 0s
        { [2] = 2 }, // colunas 0 e 1 da linha 4 sao inicializadas com 0s
    };

    // Imprime alguns valores salteados da matriz inicializada
    printf("Valor na linha 1, coluna 2 da inicializada: %d\n", matriz[1][2]);

    // Preenchimento da matriz nao inicializada
    int lin, col;
    /*
    for (lin=0; lin<LINHAS; ++lin) {
        for (col=0; col<COLUNAS; ++col) {
            printf("Digite o valor a ocupar a posicao [%d][%d]: ", lin, col);
            scanf("%d", &tabela[lin][col]);
        }
    }
    printf("Voce digitou %d para a posicao 3, 1.\n", tabela[3][1]);
    for (lin=0; lin<LINHAS; ++lin) {
        printf("| ");
        for (col=0; col<COLUNAS; ++col) {
            printf("%3d ", tabela[lin][col]);
        }
        printf("|\n");
    }
    */
    puts("Matriz inicializada:");
    for (lin=0; lin<LINHAS; ++lin) {
        printf("| ");
        for (col=0; col<COLUNAS; ++col) {
            printf("%3d ", matriz[lin][col]);
        }
        printf("|\n");
    }
    puts("Matriz exibida na forma transposta:");
    for (col=0; col<COLUNAS; ++col) {
        printf("| ");
        for (lin=0; lin<LINHAS; ++lin) {
            printf("%3d ", matriz[lin][col]);
        }
        printf("|\n");
    }

    // Chama uma funcao para encontrar o maior elemento da matriz
    int maior = maior_da_matriz(LINHAS, COLUNAS, matriz);
    printf("O maior valor eh %d.\n", maior);

    return EXIT_SUCCESS;
}

int maior_da_matriz(size_t lin, size_t col, int mat[lin][col]) {
    int maior = mat[0][0];
    int l, c;
    for (l=0; l<lin; ++l) {
        for (c=0; c<col; ++c) {
            if (maior < mat[l][c]) {
                maior = mat[l][c];
            }
        }
    }
    return maior;
}
