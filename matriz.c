#include <stdlib.h>
#include <stdio.h>

#define NUM_LINHAS 2
#define NUM_COLUNAS 3

void imprime_matriz(int, int, int[*][*]);

int main(void) {
/*
    // Declaracoes de matrizes de numeros inteiros:
    // a) matriz de duas linhas por tres colunas
    int m1[2][3];

    // b) matriz de tres linhas por duas colunas
    int m2[3][2];

    // c) matriz de tres linhas por duas colunas por cinco planos de profundidade
    int m3[3][2][5];

    // d) matriz inicializada
    int m4[2][3] = {    // "vetor de vetores"
        { 1, 2, 3 },    // 1a. linha
        { 4, 5, 6 }     // 2a. linha
    };

    // e) forma alternativa de inicializacao
    int m5[2][3] = { 1, 2, 3, 4, 5, 6 }; // preenche por linha

    // f) forma incompleta de inicializacao
    int m6[][3] = { // somente o primeiro pode ficar vazio
        { 1, 2, 3 },    // 1a. linha
        { 4, 5, 6 }     // 2a. linha
    };

    // g) inicializacao da matriz transposta de (f)
    int m6t[][2] = {
        { 1, 4 }, { 2, 5 }, { 3, 6 }
    };

    // h) inicializacao incompleta com preenchimento com zeros no final
    int m7[2][3] = {
        { 1 },      // demais elementos da 1a. linha serao zerados
        { 4, 5, 6 }
    };

    // i) inicializacao incompleta com preenchimento de zeros intermediarios
    int m8[3][3] = {
        { 1, [2] = 3 }, // pulou a coluna de indice 2
        [2] = { 7, 8, 9 } // pulou a linha de indice 1
    };
*/
    int matriz[NUM_LINHAS][NUM_COLUNAS]; // 2x3

    // Atribuicao ao ultimo elemento da primeira linha
    matriz[0][NUM_COLUNAS-1] = 5;
    matriz[1][0] = 3; // na primeira coluna (indice 0) da segunda linha (indice 1)

    /* CUIDADO: Isto eh aceito pelo compilador mas tem efeitos potencialmente
     * catastroficos
     * matriz[2][3] = 10; // C nao faz verificacao de limites (do vetor ou da matriz)
     */
    
    int lin, col; // variaveis-indices para percurso na matriz atraves dos lacos

    // Preenchimento da matriz eh similar ao vetor
    // 1a. variante de percurso: linha a linha
    for (lin = 0; lin < NUM_LINHAS; ++lin) {
        for (col = 0; col < NUM_COLUNAS; ++col) {
            printf("Digite um numero para a posicao [%d][%d]: ", lin, col);
            scanf("%d", &matriz[lin][col]);
        }
    }

    // Soma dos valores de cada coluna
    // 2a. variante de percurso: coluna a coluna
    int vetor_somas[NUM_COLUNAS] = {}; // valores iniciais zerados

    for (col = 0; col < NUM_COLUNAS; ++col) {
        for (lin = 0; lin < NUM_LINHAS; ++lin) {
            vetor_somas[col] += matriz[lin][col];
        }
    }

    // Chama funcao para imprimir a matriz
    imprime_matriz(NUM_LINHAS, NUM_COLUNAS, matriz);

    // Imprime o vetor de somas
    for (col = 0; col < NUM_COLUNAS; ++col) {
        printf("Soma da coluna %d = %d\n", col, vetor_somas[col]);
    }
    return EXIT_SUCCESS;
}

// A ordem indicada para passagem dos parametros eh como abaixo: primeiro as
// dimensoes (num. de linhas e de colunas), em seguida a propria matriz
void imprime_matriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    int l, c;
    for (l = 0; l < linhas; ++l) {
        // Comeca impressao da nova linha
        printf("| ");
        for (c = 0; c < colunas; ++c) {
            printf("%3d ", matriz[l][c]);
        }
        // Terminou a linha
        puts("|");
    }
}

