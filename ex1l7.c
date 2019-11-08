#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include "ex1l7.h"

int main(void) {
    size_t num_funcionarios;
    printf("Quantos funcionarios? ");
    scanf("%zu", &num_funcionarios);

    funcionario grupo[num_funcionarios];

    int f;
    for (f = 0; f < num_funcionarios; ++f) {
        printf("Matricula? ");
        scanf("%d", &grupo[f].matricula);

        printf("Nome? ");
        __fpurge(stdin); // limpa entradas anteriores
        gets(grupo[f].nome);

        printf("Salario-base? ");
        scanf("%f", &grupo[f].salario);

        printf("Vendas? ");
        scanf("%f", &grupo[f].vendas);
    }

    roda_folha_pagamentos(grupo, num_funcionarios);

    float soma_vendas = 0.0, soma_comissoes = 0.0, soma_salarios = 0.0;
    for (f = 0; f < num_funcionarios; ++f) {
        printf("%5d %20s %7.2f %7.2f %7.2f %7.2f\n",
               grupo[f].matricula, grupo[f].nome, grupo[f].salario,
               grupo[f].vendas, grupo[f].comissao, grupo[f].total);
        soma_vendas += grupo[f].vendas;
        soma_comissoes += grupo[f].comissao;
        soma_salarios += grupo[f].total;
    }
    printf("TOTAIS: Vendas = %.2f; comissoes = %.2f; salarios = %.2f\n",
           soma_vendas, soma_comissoes, soma_salarios);

    return EXIT_SUCCESS;
}

void roda_folha_pagamentos(funcionario folha[], size_t num) {
    int i;
    for (i = 0; i < num; ++i) {
        folha[i].comissao = 6 * folha[i].vendas / 100;
        folha[i].total = folha[i].salario + folha[i].comissao;
    }
}

