#include <stdlib.h>
#include <stdio.h>

// Prototipo da funcao
unsigned qtos_xy_encontrados(size_t, size_t, int [*][*], int, int);

#define LINHAS 3
#define COLUNAS 4

int main(void) {
    int fibonacci[LINHAS][COLUNAS] = {
        { 1, 1, 2, 3 },
        { 5, 8, 13, 21 },
        { 34, 55, 89, 144 }
    };
    int x;
    printf("Digite x: ");
    scanf("%d", &x);
    int y;
    do {
        printf("Digite y: ");
        scanf("%d", &y);
    } while (y < x); // para garantir uma comparacao de x (menor) ateh y (maior)
    
    unsigned qtde = qtos_xy_encontrados(LINHAS, COLUNAS, fibonacci, x, y);
    
    printf("Foram encontradas %u ocorrencias no intervalo [%d,%d].\n", qtde, x, y);
    
    return EXIT_SUCCESS;
}

unsigned qtos_xy_encontrados(size_t linhas, size_t colunas,
                             int matriz[linhas][colunas], int menor, int maior) {
    unsigned contador = 0;
    int l = 0;
    while (l < linhas) {    // percorrendo a matriz com while ao inves de for :-)
        int c = 0;
        while (c < colunas) {
            if (matriz[l][c] >= menor && matriz[l][c] <= maior) {
                ++contador;
            }
            ++c;
        }
        ++l;
    }
    return contador;
}
