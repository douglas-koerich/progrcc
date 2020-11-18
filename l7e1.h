#ifndef L7E1_H
#define L7E1_H

#define MAX_NOME 30

#include <stdlib.h>

// Modelagem do tipo "funcionario" na solucao do problema
struct funcionario {
    int matricula;                                          // inteiro
    char nome[MAX_NOME];                                    // string
    float salario_fixo, vendas, comissao, salario_final;    // reais
};
typedef struct funcionario Funcionario;

// Prototipos de funcoes relacionadas
void preenche_tabela_funcionarios(Funcionario*, size_t); // sem 'const' porque vai alterar
void imprime_tabela_funcionarios(const Funcionario*, size_t); // com 'const' quando eh somente-leitura

#endif // L7E1_H