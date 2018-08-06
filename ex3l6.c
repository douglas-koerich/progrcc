#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Declaracao do prototipo da funcao
int contaElementos(size_t, size_t, int[*][*], int, int);

int main(void) {
    srand((unsigned) time(0));
    unsigned linhas, colunas;

    do {
        printf("Digite o numero de linhas da matriz a ser gerada: ");
        scanf("%u", &linhas);
    } while (linhas <= 1 || linhas > 10);
    do {
        printf("Digite o numero de colunas da matriz: ");
        scanf("%u", &colunas);
    } while (colunas <= 1 || colunas > 10);

    // Eh possivel declarar uma matriz com dimensoes variaveis
    int matriz[linhas][colunas];

    // Gera e imprime a matriz
    int l, c;
    for (l=0; l<linhas; ++l) {
        for (c=0; c<colunas; ++c) {
            matriz[l][c] = rand() % 50;
            printf("%2d ", matriz[l][c]);
        }
        putchar('\n');
    }

    // Pede os valores limites do intervalo
    int x, y;
    printf("Digite o limite inferior (x): ");
    scanf("%d", &x);
    printf("Digite o limite superior (y): ");
    scanf("%d", &y);

    // Chama a funcao para calcular quantos elementos estao no intervalo fechado [x,y]
    // ATENCAO: as dimensoes da matriz sao passadas ANTES da mesma na lista de parametros
    int num = contaElementos(linhas, colunas, matriz, x, y);
    printf("Sao %d elementos no intervalo selecionado.\n", num);

    return EXIT_SUCCESS;
}

int contaElementos(size_t num_linhas, size_t num_colunas, int mat[num_linhas][num_colunas], int lim_inf, int lim_sup) {
    int contador = 0, lin, col;
    for (lin=0; lin<num_linhas; ++lin) {
        for (col=0; col<num_colunas; ++col) {
            // Testa se NAO pertence ao intervalo
            if (mat[lin][col] < lim_inf || mat[lin][col] > lim_sup) {
                ++contador;
            }
        }
    }
    return contador;
}

