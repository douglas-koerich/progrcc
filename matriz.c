#include <stdlib.h>
#include <stdio.h>

// Faca um programa que leia uma matriz de numeros inteiros de dimensoes
// NxM e calcule a soma dos elementos que estao acima da diagonal principal
// (excluindo os que estao na mesma)

#define LINHAS 3
#define COLUNAS 4

void imprime(size_t, size_t, int [*][*]);
int soma_sup(size_t, size_t, int [*][*]);

int main(void) {
    size_t N, M;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%zu", &N);
    printf("Digite o numero de colunas: ");
    scanf("%zu", &M);

    // Exemplo: matriz 2x3
    //    0   1   2
    //   +--+---+--+
    // 0 |3  -1  12
    // 1 |5   4   0

    // Declaracao da matriz
    int matriz[N][M];  // CUIDADO, nao eh [N, M]

    // Percurso na matriz (por linha)
    int lin, col;
    for (lin = 0; lin < N; ++lin) {
        for (col = 0; col < M; ++col) {
            printf("Digite o valor da posicao [%d][%d]: ", lin, col);
            scanf("%d", &matriz[lin][col]);
        }
    }

    // Chama funcao que imprime a matriz
    imprime(N, M, matriz);
    
    // Chama funcao que calcula a soma do triangulo superior
    int soma = soma_sup(N, M, matriz);

    printf("\nA soma dos elementos acima da diagonal principal eh %d.\n", soma);

    // [Off-topic] Inicializacoes validas de uma matriz
    int m1[LINHAS][COLUNAS] = {
        { 0, 1, 6, 3 }, // linha 0
        { 9, 3, 4, 5 }, // linha 1
        { 7, 8, 2, 0 }  // linha 2
    };
    int m2[][COLUNAS] = { // o numero dentro do primeiro par eh deduzido
        { 0, 1, 6, 3 }, // linha 0
        { 9, 3, 4, 5 }, // linha 1
        { 7, 8, 2, 0 }  // linha 2
    };
    int m3[LINHAS][COLUNAS] = { { } }; // matriz totalmente ZERADA
    int m4[LINHAS][COLUNAS] = {
        { 0, 1, 6, 3 }, // linha 0
        { },            // linha 1 ZERADA
        { 7, 8, 2, 0 }  // linha 2
    };
    int m5[LINHAS][COLUNAS] = {
        { 0, 1, 6, 3 }, // linha 0
        { 9, 3 },       // linha 1 parcialmente ZERADA
        { 7, 8, 2, 0 }  // linha 2
    };
    int m6[LINHAS][COLUNAS] = {
        [1] = { 9, 3 },    // linha 1 parcialmente ZERADA, e a linha 0 totalmente ZERADA
        { [1] = 8, 2, 0 }  // linha 2 com a coluna 0 (indice [0]) ZERADA
        // { 7, [2] = 2, 0 } <-- neste caso os indices de coluna 0, 2 e 3 estao inicializados
    };

    return EXIT_SUCCESS;
}

void imprime(size_t l, size_t c, int m[l][c]) {
    putchar('\n'); // garante um salto de linha antes...
    int i, j;
    for (i = 0; i < l; ++i) {
        for (j = 0; j < c; ++j) {
            printf("%3d ", m[i][j]);
        }
        putchar('\n'); // ... e um salto de linha a cada nova linha
    }
}

int soma_sup(size_t l, size_t c, int m[l][c]) {
    int i, j, s;
    for (i = s = 0; i < l; ++i) {
        for (j = 0; j < c; ++j) {
            if (j > i) { // somente se estah acima da diagonal principal
                s += m[i][j];
            }
        }
    }
    return s;
}

