#ifndef EX1L7_H
#define EX1L7_H

#include <stdlib.h> // para uso do size_t

#define MAX_NOME 80

struct funcionario {
    int matricula;
    char nome[MAX_NOME];
    float salario;
    float vendas;
    float comissao;
    float total;
    /* Poderia ser:
     * int matricula;
     * char nome[MAX_NOME];
     * float salario, vendas, comissao, total;
     */
};
typedef struct funcionario funcionario; // pode ser o mesmo nome

void roda_folha_pagamentos(funcionario [*], size_t);

#endif // EX1L7_H

