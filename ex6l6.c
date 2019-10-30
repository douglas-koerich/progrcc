#include <stdlib.h>
#include <stdio.h>

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

    // Outra matriz com o mesmo tamanho...
    int rotacionada[dimensao][dimensao];

    int rot, rotacoes = absoluto / 90;
    if (angulo < 0) { // horario? --> transposta normal
        for (rot = 1; rot <= rotacoes; ++rot) {
            for (lin = 0; lin < dimensao; ++lin) {
                for (col = 0; col < dimensao; ++col) {
                    rotacionada[col][lin] = matriz[lin][col];
                }
            }
        }
    } else {
        // (... Para Casa ...)
    }
    // (... Impressao ...)

    return EXIT_SUCCESS;
}

