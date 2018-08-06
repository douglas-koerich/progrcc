#include <stdlib.h>
#include <stdio.h>

void mult_matriz_maior_elem(size_t, int[*][*], int[*][*]);

#define TAM_MATRIZ  2

int main(void) {
    int matriz[TAM_MATRIZ][TAM_MATRIZ];
    int lin, col;
    for (lin = 0; lin < TAM_MATRIZ; ++lin) {
        for (col = 0; col < TAM_MATRIZ; ++col) {
            printf("Digite o valor do elemento [%d][%d]: ", lin, col);
            scanf("%d", &matriz[lin][col]);
        }
    }
    int mult[TAM_MATRIZ][TAM_MATRIZ];
    mult_matriz_maior_elem(TAM_MATRIZ, matriz, mult);
    puts("Matriz original:");
    for (lin = 0; lin < TAM_MATRIZ; ++lin) {
        for (col = 0; col < TAM_MATRIZ; ++col) {
            printf("%4d ", matriz[lin][col]);
        }
        putchar('\n');  // proxima linha na tela
    }
    puts("Matriz multiplicada:");
    for (lin = 0; lin < TAM_MATRIZ; ++lin) {
        for (col = 0; col < TAM_MATRIZ; ++col) {
            printf("%4d ", mult[lin][col]);
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}

void mult_matriz_maior_elem(size_t dimensao,    // uma dimensao basta porque eh quadrada
                            int M[dimensao][dimensao],  // matriz de entrada
                            int R[dimensao][dimensao])  // matriz de saida
{
    int l, c, maior = M[0][0];  // inicia maior com o primeiro elemento da matriz
    for (l = 0; l < dimensao; ++l) {
        for (c = 0; c < dimensao; ++c) {
            if (maior < M[l][c]) {
                maior = M[l][c];
            }
        }
    }
    for (l = 0; l < dimensao; ++l) {
        for (c = 0; c < dimensao; ++c) {
            R[l][c] = M[l][c] * maior;
        }
    }
}
