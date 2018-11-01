#include <stdlib.h>
#include <stdio.h>

#define LINHAS 4
#define COLUNAS 5

int soma(size_t, size_t, int [*][*]); // dimensoes vem antes da matriz nos parametros

int main(void) {
    int matriz[LINHAS][COLUNAS]; // nao eh [LINHAS, COLUNAS]

    int inicializada_1[LINHAS][COLUNAS] = {
        { 1, 2, 3, 4, 5 }, // todas as posicoes da linha preenchidas
        { 6, 7, 8 }, // preenche o restante da linha com zeros
        [3] = { [2] = 9, 10, 11 } // soh vale para C99: pulou a linha 2 (toda zerada)
                                  // preenche a partir da coluna 2 (anteriores zeradas)
    };
    /*
    int inicializacao_invalida[][] = {
        { 1, 2 },
        { 3, 4 }
    };
    */
    int inicializacao_valida[][2] = { // somente o primeiro [] pode ser deixado vazio
        { 1, 2 },
        { 3, 4 }
    };

    puts("Primeira impressao: matriz original");
    int linha, coluna;
    // Para cada uma das linhas...
    for (linha=0; linha<LINHAS; ++linha) {
        // ... essa linha tem varias colunas, percorre-as...
        for (coluna=0; coluna<COLUNAS; ++coluna) {
            printf("%2d ", inicializada_1[linha][coluna]);
        }
        // Ao concluir uma linha, inicia nova linha na tela
        putchar('\n');
    }
    puts("Segunda impressao: matriz transposta (colunas vs. linhas)");
    // Para cada uma das colunas...
    for (coluna=0; coluna<COLUNAS; ++coluna) {
        // ... essa coluna tem varias linhas, percorre-as...
        for (linha=0; linha<LINHAS; ++linha) {
            printf("%2d ", inicializada_1[linha][coluna]); // ordem dos colchetes NAO se altera!
        }
        putchar('\n');
    }

    printf("A soma dos elementos da matriz eh %d.\n", soma(LINHAS, COLUNAS, inicializada_1));

    return EXIT_SUCCESS;
}

// Na passagem de parametros para a funcao, as variaveis correspondentes ahs dimensoes
// devem ser declaradas/listadas antes da matriz propriamente dita
int soma(size_t lins, size_t cols, int mat[lins][cols]) {
    int l, c, s;
    for (s=l=0; l<lins; ++l) {
        for (c=0; c<cols; ++c) {
            s += mat[l][c];
        }
    }
    return s;
}

