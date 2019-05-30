#include <stdlib.h>
#include <stdio.h>
#include "exerc1_lista7.h"

#define NUM_FUNC 5

int main(void) {
    struct funcionario grupo[NUM_FUNC];
    int f;
    for (f = 0; f < NUM_FUNC; ++f) {
        printf("Salario do func. %d: ", f+1);
        scanf("%f", &grupo[f].salario_base);
        printf("Vendas do func. %d: ", f+1);
        scanf("%f", &grupo[f].vendas);
        grupo[f].comissao = grupo[f].vendas * 0.06;
        grupo[f].salario_final = grupo[f].salario_base + grupo[f].comissao;
    }
    float total_base = 0.0, total_vendas = 0.0, total_comissao = 0.0, total_final = 0.0;
    puts(">>> TABELA DE RESULTADOS <<<");
    printf("%20s %20s %20s %20s\n", "Salario-base", "Vendas", "Comissao", "Salario Final");
    for (f = 0; f < NUM_FUNC; ++f) {
        printf("%20.2f %20.2f %20.2f %20.2f\n", grupo[f].salario_base, grupo[f].vendas,
               grupo[f].comissao, grupo[f].salario_final);
        total_base += grupo[f].salario_base;
        total_vendas += grupo[f].vendas;
        total_comissao += grupo[f].comissao;
        total_final += grupo[f].salario_final;
    }
    printf("\n%20.2f %20.2f %20.2f %20.2f\n", total_base, total_vendas, total_comissao,
           total_final);

    return EXIT_SUCCESS;
}

