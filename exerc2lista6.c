#include <stdlib.h>
#include <stdio.h>
#include <time.h>   // para uso do relogio como semente do rand()

#define NUM_MESES 12
#define NUM_PRODUTOS 4

int main(void) {
    // O uso de const na frente de uma variavel indica que a mesma
    // nao pode ser alterada pelo programa
    const char nomes_meses[NUM_MESES][4] = {
        "jan", "fev", "mar", "abr", "mai", "jun",
        "jul", "ago", "set", "out", "nov", "dez"
    };
    const char nomes_produtos[NUM_PRODUTOS][20] = {
        "Prego", "Porca", "Arruela", "Parafuso"
    };
    
    // Inicializa gerador de numeros pseudo-aleatorios com um valor
    // realmente unico, que eh o relogio atual do sistema
    srand((unsigned) time(0));
    
    // A tabela a ser preenchida
    unsigned tabela[NUM_PRODUTOS][NUM_MESES];
    
    // Para ilustracao do funcionamento do programa, ao inves de preencher
    // a tabela com leituras individuais (scanf's) dos valores, vamos
    // gerar numeros aleatorios de 1000 a 4000, como no enunciado...
    int linha, coluna;
    for (linha = 0; linha < NUM_PRODUTOS; ++linha) { // para cada produto...
        for (coluna = 0; coluna < NUM_MESES; ++coluna) { // para cada mes...
            tabela[linha][coluna] = rand() % 3001 + 1000; // de 1000 a 4000...
        }
    }
    
    // Somatorios:
    unsigned total_anual_produtos[NUM_PRODUTOS] = {}; // vazio = todos zerados
    unsigned total_mensal_empresa[NUM_MESES] = {};    // idem
    
    // A primeira soma (a) eh obtida por um percurso em linha na tabela
    for (linha = 0; linha < NUM_PRODUTOS; ++linha) {
        for (coluna = 0; coluna < NUM_MESES; ++coluna) {
            total_anual_produtos[linha] += tabela[linha][coluna];
        }
    }
    // A segunda soma (b) eh obtida por um percurso em colunas
    for (coluna = 0; coluna < NUM_MESES; ++coluna) {
        for (linha = 0; linha < NUM_PRODUTOS; ++linha) {
            total_mensal_empresa[coluna] += tabela[linha][coluna];
        }
    }
    
    // Imprime toda a tabela, com as somas
    printf("%8s ", "Produto"); // %8s para imprimir uma string com pelo menos 8 simbolos
    for (coluna = 0; coluna < NUM_MESES; ++coluna) {
        printf("%5s ", nomes_meses[coluna]);
    }
    printf("%6s\n", "TOTAL");   // coluna adicional para o total de cada produto
    for (linha = 0; linha < NUM_PRODUTOS; ++linha) {
        printf("%8s ", nomes_produtos[linha]);  // comeca linha com nome do produto
        for (coluna = 0; coluna < NUM_MESES; ++coluna) {
            printf("%5u ", tabela[linha][coluna]);
        }
        printf("%6u\n", total_anual_produtos[linha]); // termina linha com total
    }
    // Linha adicional com totais de cada mes
    printf("%8s ", "TOTAL");
    for (coluna = 0; coluna < NUM_MESES; ++coluna) {
        printf("%5u ", total_mensal_empresa[coluna]);
    }
    putchar('\n');
    
    return EXIT_SUCCESS;
}