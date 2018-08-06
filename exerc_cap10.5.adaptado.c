#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>  // __fpurge (Linux)
#include "exerc_cap10.5.adaptado.h"

void cadastro_funcionario(struct Funcionario [*], size_t*);
void calcula_valores(struct Funcionario*);
void imprime_folha_pagamento(const struct Funcionario*, size_t);

int main(void) {
    int opcao;
    remove(NOME_ARQUIVO); // apaga arquivo de execucao anterior
    struct Funcionario banco_dados[NUM_FUNCIONARIOS];
    size_t num_funcionarios_cadastrados = 0;
    do {
        puts("*** Exercicio 5 do capitulo 10 do livro da Ascencio ***");
        puts("1. Cadastrar funcionarios");
        puts("2. Mostrar folha de pagamento");
        puts("3. Sair");
        printf("Digite a operacao desejada: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                // Passa o endereco do contador para que a funcao de cadastro
                // possa atualiza-lo apos novas insercoes
                cadastro_funcionario(banco_dados, &num_funcionarios_cadastrados);
                break;

            case 2:
                imprime_folha_pagamento(banco_dados, num_funcionarios_cadastrados);
                break;

            case 3:
                // Faz nada...
                break;

            default:
                puts("Operacao invalida, tente novamente!");
        }
    } while (opcao != 3);
    return EXIT_SUCCESS;
}

void calcula_valores(struct Funcionario* func) {
    float coeficiente;
    if (func->categoria == 'G') {
        // Estrutura condicional completa classica
        if (func->turno == 'N') {
            coeficiente = 0.18;
        } else {
            coeficiente = 0.15;
        }
    } else {
        // Operador ternario no lugar da estrutura condicional classica
        coeficiente = func->turno == 'N'? 0.13: 0.10;
    }
    func->valor_hora = SAL_MINIMO * coeficiente;
    func->salario_base = func->horas_trabalhadas * func->valor_hora;
    if (func->salario_base <= 2*SAL_MINIMO) {
        coeficiente = 0.20;
    } else {
        if (func->salario_base > 5*SAL_MINIMO) {
            coeficiente = 0.05;
        } else {
            coeficiente = 0.15;
        }
    }
    func->auxilio_alimentacao = func->salario_base * coeficiente;
    func->salario_final = func->salario_base + func->auxilio_alimentacao;
}

void cadastro_funcionario(struct Funcionario cadastro[], size_t* contador) {
    // A variavel 'contador' nao eh um inteiro, eh um endereco para um
    // inteiro; precisa usar o * para chegar ao valor armazenado no endereco
    while (*contador < NUM_FUNCIONARIOS) {
        puts("Digite abaixo o nome do novo funcionario (X para interromper):");
        __fpurge(stdin);
        gets(cadastro[*contador].nome); // contador atual = indice da primeira posicao livre
        if (strcmp(cadastro[*contador].nome, "X") == 0) { // igual a X?
            return; // fim do cadastro nesta rodada...
        }
        printf("Numero de horas trabalhadas: ");
        scanf("%u", &cadastro[*contador].horas_trabalhadas);
        char c;
        do {
            printf("Turno (M/V/N): ");
            __fpurge(stdin);        // limpa o teclado antes de ler char/string
            c = toupper(getchar()); // le do teclado e converte pra maiuscula
        } while (c != 'M' && c != 'V' && c != 'N');
        cadastro[*contador].turno = c;
        do {
            printf("Categoria (O/G): ");
            __fpurge(stdin);
            c = toupper(getchar());
        } while (c != 'O' && c != 'G');
        cadastro[*contador].categoria = c;

        // Chama a funcao que calcula os valores para o novo funcionario
        calcula_valores(&cadastro[*contador]);  // passa endereco para alterar o registro

        // Acrescenta o novo registro ao arquivo
        FILE* arquivo = fopen(NOME_ARQUIVO, "a+b");
        if (arquivo == NULL) {
            perror("Nao pude abrir o arquivo");
            exit(EXIT_FAILURE); // sai do programa deste(!) ponto
        }
        if (fwrite(&cadastro[*contador], sizeof(struct Funcionario), 1, arquivo) < 1) {
            perror("Nao pude acrescentar ao arquivo");
            exit(EXIT_FAILURE);
        }
        fclose(arquivo);

        ++(*contador);  // precisa do parenteses para nao aplicar ++ no ponteiro,
                        // e sim no valor armazenado
    }
} 

void imprime_folha_pagamento(const struct Funcionario* cadastro, size_t num_funcionarios) {
    system("clear");    // chama o shell pra limpar a tela do programa
    puts("********* ACME *********");
    puts("COMPANHIA DE ITENS GENERICOS PARA O COIOTE DETONAR O PAPA-LEGUAS");
    printf("%-20s %10s %10s %10s\n", "NOME", "SAL.BASE", "AUXILIO", "SAL.FINAL");
    int i;
    for (i=0; i<num_funcionarios; ++i) {
        printf("%-20s %10.2f %10.2f %10.2f\n", cadastro[i].nome, cadastro[i].salario_base,
               cadastro[i].auxilio_alimentacao, cadastro[i].salario_final);
    }
    puts("*** (FIM DOS REGISTROS) ***\n");
}

