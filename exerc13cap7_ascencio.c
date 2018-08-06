#include <stdlib.h>
#include <stdio.h>
#include "mygets.h"

#define MAX_NOME_PRODUTO    30
#define NUM_PRODUTOS        5
#define NUM_LOJAS           4

int main(void) {
    // Vetor de nomes dos produtos
    char nomes[NUM_PRODUTOS][MAX_NOME_PRODUTO+1]; // vetor de strings (que sao vetores)...
    float precos[NUM_PRODUTOS][NUM_LOJAS];
    float custo_transporte[NUM_PRODUTOS];

    // Entrada de dados:
    int prod, loja;
    for (prod = 0; prod < NUM_PRODUTOS; ++prod) {
        printf("Digite o nome do produto #%d: ", prod+1);
        Gets(nomes[prod], MAX_NOME_PRODUTO+1);

        printf("Digite o custo para transporta-lo: ");
        scanf("%f", &custo_transporte[prod]);

        puts("Agora, digite o preco nas lojas");
        for (loja = 0; loja < NUM_LOJAS; ++loja) {
            printf("Loja #%d: ", loja+1);
            scanf("%f", &precos[prod][loja]);
        }
    }
    // Impostos dos produtos (depende do preco de cada loja):
    float impostos[NUM_PRODUTOS][NUM_LOJAS];
    for (prod = 0; prod < NUM_PRODUTOS; ++prod) {
        for (loja = 0; loja < NUM_LOJAS; ++loja) {
            if (precos[prod][loja] < 50.00) {
                impostos[prod][loja] = precos[prod][loja] * .05;
            } else if (precos[prod][loja] > 100.00) {
                impostos[prod][loja] = precos[prod][loja] * .2;
            } else {
                impostos[prod][loja] = precos[prod][loja] * .1;
            }
        }
    }
    // Relatorio final:
    puts("$$$$$ RELATORIO $$$$$");
    for (prod = 0; prod < NUM_PRODUTOS; ++prod) {
        printf("\nPRODUTO: %s\n", nomes[prod]);
        for (loja = 0; loja < NUM_LOJAS; ++loja) {
            printf("  Loja %d:\n", loja+1);
            printf("    Preco   : %7.2f\n", precos[prod][loja]);
            printf("    Impostos: %7.2f\n", impostos[prod][loja]);
            printf("    Frete   : %7.2f\n", custo_transporte[prod]);
            printf("    TOTAL   : %7.2f\n",
                   precos[prod][loja]+impostos[prod][loja]+custo_transporte[prod]);
        }
    }
    puts("$$ FIM DO RELATORIO $");
    return EXIT_SUCCESS;
}

