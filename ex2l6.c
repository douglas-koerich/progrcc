#include <stdlib.h>
#include <stdio.h>
#include <time.h>   // para usar srand() -> nao faz parte do exercicio!

#define LINHAS  4   // (quatro produtos)
#define COLUNAS 12  // (doze meses)

// Variaveis globais
// Lista (vetor) de strings contendo os nomes dos produtos
#define MAX_NOME_PRODUTO    10
const char PRODUTOS[][MAX_NOME_PRODUTO] = { "Prego", "Porca", "Arruela", "Parafuso" };
/***** Um vetor de strings eh, na verdade, uma matriz de caracteres! *****/

// Lista de abreviaturas dos meses
const char MESES[][4] = { "jan", "fev", "mar", "abr", "mai", "jun",     // [4] para reservar lugar ao '\0'
                          "jul", "ago", "set", "out", "nov", "dez" };

int main(void) {
    srand((unsigned) time(0));      // usa como semente o tick atual do relogio do PC

    // Declaracao da matriz
    int tabela[LINHAS][COLUNAS];    // matriz 4 x 12

    // Leitura dos valores de cada posicao da matriz
    // (sentido de leitura convencional, linha a linha)
    int lin, col;
    for (lin=0; lin<LINHAS; ++lin) {
        // Imprime a string-nome de produto da vez
        printf("Digite o numero de barris de %s para cada mes abaixo:\n", PRODUTOS[lin]);
        for (col=0; col<COLUNAS; ++col) {
            printf("%s==> ", MESES[col]);
            // scanf("%d", &tabela[lin][col]);
            // Substituida a leitura pela geracao randomica para agilizar a demonstracao do programa
            tabela[lin][col] = rand() % 200 + 801;  // um numero entre 801 e 1000
            printf("%d\n", tabela[lin][col]);       // mostra o numero gerado
        }
    }

    // Declara os totalizadores, inicializando-os
    int total_produto[LINHAS] = { 0 }, total_mes[COLUNAS] = { 0 };

    // Para totalizar por produto, percorre a tabela linha a linha, somando no final de cada linha
    for (lin=0; lin<LINHAS; ++lin) {
        for (col=0; col<COLUNAS; ++col) {
            total_produto[lin] += tabela[lin][col];
        }
    }

    // Para totalizar por mes, percorre a tabela coluna a coluna, somando no final de cada coluna
    for (col=0; col<COLUNAS; ++col) {
        for (lin=0; lin<LINHAS; ++lin) {
            total_mes[col] += tabela[lin][col];
        }
    }

    // Impressao da tabela e seus totais
    // Linha de cabecalho:
    printf("Produto    ");
    for (col=0; col<COLUNAS; ++col) {
        printf(" %s ", MESES[col]); // jan, fev, mar, ...
    }
    puts("TOTAL");  // ja faz o salto de linha
    for (lin=0; lin<LINHAS; ++lin) {
        printf("%-10s ", PRODUTOS[lin]); // Coluna de cabecalho (nome alinhado a esquerda)
        for (col=0; col<COLUNAS; ++col) {
            printf("%4d ", tabela[lin][col]);
        }
        printf("%4d\n", total_produto[lin]);
    }
    // Linha de rodape (totais de cada mes)
    printf("TOTAL      ");
    for (col=0; col<COLUNAS; ++col) {
        printf("%4d ", total_mes[col]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

