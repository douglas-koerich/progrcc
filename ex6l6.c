#include <stdlib.h>
#include <stdio.h>

// No caso de passagem de matriz como parametro, passam-se antes
// suas dimensoes e depois a propria matriz
void imprime(size_t, size_t, int [*][*]);

void copia(size_t, size_t, int [*][*], const int [*][*]);

int main(void) {
    size_t dimensao;
    printf("Digite a dimensao da matriz quadrada: ");
    scanf("%zd", &dimensao);

    // Declara uma matriz de tamanho "variavel"
    int matriz[dimensao][dimensao];

    int lin, col;
    for (lin = 0; lin < dimensao; ++lin) {
        for (col = 0; col < dimensao; ++col) {
            printf("M[%d][%d]? ", lin, col);
            scanf("%d", &matriz[lin][col]);
        }
    }

    int angulo, absoluto;
    do {
        printf("Digite o angulo de rotacao: ");
        scanf("%d", &angulo);
        absoluto = angulo < 0? -angulo: angulo;
    } while (absoluto != 90 && absoluto != 180 && absoluto != 270);

    // Outra matriz com o mesmo tamanho, mais uma extra pra ajudar
    // na rotacao com angulo > |90|...
    int rotacionada[dimensao][dimensao],
        auxiliar[dimensao][dimensao];
    int rot, rotacoes = absoluto / 90;

    // Copia a original para a auxiliar
    copia(dimensao, dimensao, auxiliar, matriz);

    for (rot = 1; rot <= rotacoes; ++rot) {
        if (angulo < 0) { // horario?
            for (lin = dimensao-1; lin >= 0; --lin) {
                for (col = 0; col < dimensao; ++col) {
                    rotacionada[col][dimensao-lin-1] = auxiliar[lin][col];
                }
            }
        } else {
            for (col = dimensao-1; col >= 0; --col) {
                for (lin = 0; lin < dimensao; ++lin) {
                    rotacionada[dimensao-col-1][lin] = auxiliar[lin][col];
                }
            }
        }
        copia(dimensao, dimensao, auxiliar, rotacionada);
    }
    puts("Matriz original");
    imprime(dimensao, dimensao, matriz);
    puts("Matriz rotacionada");
    imprime(dimensao, dimensao, rotacionada);

    return EXIT_SUCCESS;
}

void imprime(size_t lin, size_t col, int mat[lin][col]) {
    int l, c;
    for (l = 0; l < lin; ++l) {
        for (c = 0; c < col; ++c) {
            printf("%2d ", mat[l][c]);
        }
        putchar('\n');
    }
}

void copia(size_t lin, size_t col, int dest[lin][col], const int orig[lin][col]) {
    int l, c;
    for (l = 0; l < lin; ++l) {
        for (c = 0; c < col; ++c) {
            dest[l][c] = orig[l][c];
        }
    }
}

