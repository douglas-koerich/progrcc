#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "l7e1.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Uso: %s <num-funcionarios>\n", argv[0]);
        return EXIT_FAILURE;
    }
    size_t num_funcionarios = atoi(argv[1]);

    Funcionario banco_de_dados[num_funcionarios]; // vetor de registros

    preenche_tabela_funcionarios(banco_de_dados, num_funcionarios);
    imprime_tabela_funcionarios(banco_de_dados, num_funcionarios);

    return EXIT_SUCCESS;
}

void preenche_tabela_funcionarios(Funcionario* vetor, size_t tamanho) {
    srand((unsigned) time(NULL));
    int f;

    for (f = 0; f < tamanho; ++f) {
        vetor[f].matricula = rand() % 99 + 1; // matricula aleatoria na faixa de 1 a 99
        printf("Digite o prenome do(a) %do.(a.) funcionario(a): ", f + 1);
        scanf(" %s", vetor[f].nome);
        printf("Qual eh o salario fixo de %s? ", vetor[f].nome);
        scanf("%f", &vetor[f].salario_fixo);
        printf("Qual o montante de vendas dele(a)? ");
        scanf("%f", &(vetor+f)->vendas); // aritmetica de ponteiro para chegar ao endereco do f-esimo registro

        vetor[f].comissao = vetor[f].vendas * 6 / 100;
        vetor[f].salario_final = vetor[f].salario_fixo + vetor[f].comissao;
    }
}

void imprime_tabela_funcionarios(const Funcionario* lista, size_t comprimento) {
    printf("Matr. %30s %10s %10s\n", "Nome", "Comissao", "Salario");
    int f;
    float total_comissao = 0.0, total_salario = 0.0;
    const Funcionario* pf;
    for (f = 0, pf = lista; f < comprimento; ++f, ++pf) { // cada incremento em pf "salta" um registro INTEIRO na memoria!
        printf("%5d %30s %10.2f %10.2f\n", pf->matricula, pf->nome, pf->comissao, pf->salario_final);
        total_comissao += pf->comissao;
        total_salario += pf->salario_final;
    }
    printf("TOTAL %41.2f %10.2f\n", total_comissao, total_salario);
}