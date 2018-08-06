#include <stdio.h>

int contaForaIntervalo(size_t, size_t,  // dimensoes da matriz sao passadas antes
                       int [*][*],      // da matriz, para saber qual eh qual...
                       int, int);       // esses 2 parametros sao x e y do intervalo

int main() {
    int linhas, colunas;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &colunas);

    // Declara a matriz no tamanho desejado
    int matriz[linhas][colunas];

    // Preenche a matriz para testa-la
    int lin, col;
    for (lin=0; lin<linhas; ++lin) {
        for (col=0; col<colunas; ++col) {
            printf("Digite [%d][%d]: ", lin, col);
            scanf("%d", &matriz[lin][col]);
        }
    }

    printf("Digite o valor minimo do intervalo (x): ");
    int x;
    scanf("%d", &x);
    printf("Digite o valor maximo do intervalo (y): ");
    int y;
    scanf("%d", &y);

    int contador = contaForaIntervalo(linhas, colunas, matriz, x, y);

    printf("O numero de elementos da matriz fora do intervalo [%d,%d] eh %d\n", x, y, contador);

    return 0;
}

int contaForaIntervalo(size_t num_linhas, size_t num_colunas, int mtx[num_linhas][num_colunas],
                       int x, int y) {
    int contador = 0;
    int lin, col;
    for (lin=0; lin<num_linhas; ++lin) {
        for (col=0; col<num_colunas; ++col) {
            if (mtx[lin][col] < x || mtx[lin][col] > y) {
                ++contador;
            }
        }
    }
    return contador;
}

