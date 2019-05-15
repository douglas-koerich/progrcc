#include <stdlib.h>
#include <stdio.h>

#define LINHAS 3
#define COLUNAS 4

int num_elementos_fora_do_intervalo(int, int, size_t, size_t, int [*][*]);

int main(void) {
    int matriz[LINHAS][COLUNAS], i, j;
    for (i = 0; i < LINHAS; ++i) {
        for (j = 0; j < COLUNAS; ++j) {
            printf("Digite [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Digite x: ");
    int x, y;
    scanf("%d", &x);
    do {
        printf("Digite y: ");
        scanf("%d", &y);
    } while (y < x); // nao deixa digitar um y menor que x

    int n = num_elementos_fora_do_intervalo(x, y, LINHAS, COLUNAS, matriz);
    printf("O numero de elementos fora do intervalo fechado eh %d.\n", n);

    return EXIT_SUCCESS;
}

int num_elementos_fora_do_intervalo(int x, int y, size_t l, size_t c, int m[l][c]) {
    int contador = 0;
    int i, j;
    for (i = 0; i < l; ++i) {
        for (j = 0; j < c; ++j) {
            if (m[i][j] >= x && m[i][j] <= y) {
                ++contador;
            }
        }
    }
    return contador;
}

