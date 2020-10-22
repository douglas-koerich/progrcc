#include <stdlib.h>
#include <stdio.h>

unsigned funcao(size_t, size_t, int [*][*], int, int);

#define LINHAS 2
#define COLUNAS 3

int main(void) {
    int matrix[LINHAS][COLUNAS] = {
        { 1, 2 }, // ultima coluna com valor 0
        { [1] = 3, 4} // primeira coluna com valor 0
    };
    int menor, maior;
    printf("Digite o menor valor: ");
    scanf("%d", &menor);
    printf("Digite o maior valor: ");
    scanf("%d", &maior);

    unsigned num = funcao(LINHAS, COLUNAS, matrix, menor, maior);

    printf("O numero de elementos fora do intervalo [%d,%d] eh %u\n", menor, maior, num);

    return EXIT_SUCCESS;
}

unsigned funcao(size_t linhas, size_t colunas, int matriz[linhas][colunas], int x, int y) {
    unsigned contador = 0;
    int i, j;
    for (i = 0; i < linhas; ++i) { // para cada uma das linhas...
        for (j = 0; j < colunas; ++j) { // ... percorre cada coluna dessa linha
            if (matriz[i][j] < x || matriz[i][j] > y) {
                ++contador;
            }
        }
    }
    return contador;
}