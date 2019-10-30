#include <stdlib.h>
#include <stdio.h>

// Implementa uma planilha de notas de uma turma
#define NUM_ALUNOS 10
#define NUM_NOTAS  3

int main(void) {
    // Primeira dimensao (primeiro par de []): numero de linhas
    // Segunda dimensao (segundo par): numero de colunas
    float planilha_notas[NUM_ALUNOS][NUM_NOTAS] = {}; // zerada

    /* Exemplos de inicializacao de matrizes:
     * #define LINHAS 4
     * #define COLUNAS 3
     * int mat1[LINHAS][COLUNAS] = {
     *     { 1, 0, -1 },  // primeira linha
     *     { 3, 4, 8 },   // segunda linha, ...
     *     { 5, -2, 10 },
     *     { 4, 1, 9 }
     * };
     * int mat2[LINHAS][COLUNAS] = {
     *     { 1, -1 },  // ultima coluna zerada
     *     { 3 },      // somente primeira coluna nao-zero
     *     {},         // toda a linha zerada
     *     { 4, 1, 9 } // nenhum elemento faltante
     * };
     * int mat3[LINHAS][COLUNAS] = {
     *     { [1] = 1, -1 },  // coluna [0] zerada
     *     { [2] = 5 },      // colunas [0] e [1] zeradas
     *     [3] = { 4, 1, 9 } // nao inicializou (zerou) a linha [2] (pulou!)
     * };
     * int mat4[][COLUNAS] = { // SOMENTE UM [] VAZIO!!
     *     { 1, 0, -1 },
     *     { 3, 4, 8 },
     *     { 5, -2, 10 },
     *     { 4, 1, 9 } // subentende o formato da matriz
     * };
     */

    // Percurso de preenchimento das notas, ah medida que as
    // avaliacoes sao feitas (coluna apos coluna)
    // PARA TODAS AS COLUNAS DA TABELA...
    int coluna, linha;
    for (coluna = 0; coluna < NUM_NOTAS; ++coluna) {
        // Dada uma coluna,
        // PARA TODAS AS LINHAS DA COLUNA...
        for (linha = 0; linha < NUM_ALUNOS; ++linha) {
            printf("Digite a nota no. %d do(a) %do(a). aluno(a): ", coluna+1, linha+1);
            scanf("%f", &planilha_notas[linha][coluna]);
        }
    }

    // Imprime na tela as notas e a media de cada aluno(a)
    // (linha apos linha)
    printf("%5s %5s %5s %5s\n", "AV1", "AV2", "ED", "MEDIA");
    for (linha = 0; linha < NUM_ALUNOS; ++linha) {
        float soma_notas = 0.0;
        for (coluna = 0; coluna < NUM_NOTAS; ++coluna) {
            printf("%5.1f ", planilha_notas[linha][coluna]);
            soma_notas += planilha_notas[linha][coluna];
        }
        printf("%5.1f\n", soma_notas / 3);
    }

    return EXIT_SUCCESS;
}

