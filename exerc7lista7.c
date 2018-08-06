#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <stdbool.h>
#include <ctype.h>
#include "exerc7lista7.h"
#include "mygets.h"

#define MAXIMO 100

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Use: %s <num-novos-funcionarios>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int novos = atoi(argv[1]), opcao;
    struct funcionario* lista = (struct funcionario*) malloc(MAXIMO * sizeof(struct funcionario));
    size_t usado = 0;   // quantos registros estao de fato no vetor alocado em memoria
    while (true) {  // for (;;)
        do {
            puts("*** MENU DE OPERACOES ***");
            printf("1. Cadastrar os %d novos funcionarios\n", novos);
            puts("2. Ler cadastro do arquivo");
            puts("3. Salvar cadastro no arquivo");
            puts("4. Mostrar folha de pagamento");
            puts("5. Sair");
            printf("Digite a opcao desejada ==>> ");
            scanf("%d", &opcao);
        } while (opcao < 1 || opcao > 5);
        switch (opcao) {
            case 1:
                if (novos + usado <= MAXIMO) {
                    cadastra_novos(lista, novos);
                    le_arquivo(lista, MAXIMO, &usado);
                } else {
                    puts("Espaco insuficiente no vetor em memoria!");
                }
                break;
            case 2: {
                le_arquivo(lista, MAXIMO, &usado);
                break;
            }
            case 3:
                grava_arquivo(lista, usado);
                break;
            case 4:
                mostra_folha();
                break;
            case 5:
                free(lista);
                return EXIT_SUCCESS;
        }
    }
    free(lista);
    return EXIT_SUCCESS;
}

void cadastra_novos(struct funcionario lista[], size_t novos) {
    FILE* arquivo = fopen("folha.cad", "ab");
    if (arquivo == NULL) {
        perror("Nao pude acessar o arquivo de cadastro");
        return;
    }
    int n;
    for (n=1; n<=novos; ++n) {
        struct funcionario reg_entrada;
        puts("** CADASTRO DE NOVO FUNCIONARIO **");
        printf("Nome? "); Gets(reg_entrada.nome, MAX_NOME);
        printf("Horas trabalhadas? "); scanf("%f", &reg_entrada.horas);
        char turno;
        do {
            printf("Turno (M/V/N)? "); __fpurge(stdin); turno = toupper(getchar());
        } while (turno != 'M' && turno != 'V' && turno != 'N');
        reg_entrada.turno = turno;
        char categoria;
        do {
            printf("Categoria (O/G)? "); __fpurge(stdin); categoria = toupper(getchar());
        } while (categoria != 'O' && categoria != 'G');
        reg_entrada.categoria = categoria;
        if (categoria == 'G') {
            reg_entrada.valor_hr = (turno == 'N')? 900 * 0.08 : 900 * 0.05;
        } else {
            reg_entrada.valor_hr = (turno == 'N')? 900 * 0.03 : 900 * 0.02;
        }
        reg_entrada.salario_bruto = reg_entrada.horas * reg_entrada.valor_hr;
        if (reg_entrada.salario_bruto <= 1000.0) {
            reg_entrada.auxilio_alim = 20 * reg_entrada.salario_bruto / 100;
        } else if (reg_entrada.salario_bruto < 1800.0) {
            reg_entrada.auxilio_alim = 5 * reg_entrada.salario_bruto / 100;
        } else {
            reg_entrada.auxilio_alim = 10 * reg_entrada.salario_bruto / 100;
        }
        if (fwrite(&reg_entrada, sizeof(reg_entrada), 1, arquivo) < 1) {
            perror("Nao pude salvar o novo registro");
            return;
        }
    }
    fclose(arquivo);
}

void le_arquivo(struct funcionario lista[], size_t max, size_t* usado) {
    FILE* arquivo = fopen("folha.cad", "rb");
    if (arquivo == NULL) {
        perror("Nao pude abrir o arquivo");
        return;
    }
    fseek(arquivo, 0, SEEK_END);    // posiciona no final
    long tamanho_arquivo = ftell(arquivo);  // "distancia" do inicio ateh onde estou
    size_t num_registros_no_arquivo = tamanho_arquivo/sizeof(struct funcionario);
    if (num_registros_no_arquivo > max) {
        perror("Espaco insuficiente no vetor em memoria");
        fclose(arquivo);
        return;
    }
    fseek(arquivo, 0, SEEK_SET);
    if (fread(lista, sizeof(struct funcionario), num_registros_no_arquivo, arquivo) < num_registros_no_arquivo) {
        perror("Erro ao ler o conjunto completo de registros do arquivo");
    } else {
        *usado = num_registros_no_arquivo;
    }
    fclose(arquivo);
}

void grava_arquivo(struct funcionario lista[], size_t num) {
    FILE* arquivo = fopen("folha.cad", "wb");
    if (arquivo == NULL) {
        perror("Nao pude criar/sobrescrever o arquivo");
        return;
    }
    if (fwrite(lista, sizeof(struct funcionario), num, arquivo) < num) {
        perror("Erro ao escrever o conjunto completo de registros do arquivo");
    }
    fclose(arquivo);
}

void mostra_folha(void) {
    FILE* arquivo = fopen("folha.cad", "rb");
    if (arquivo == NULL) {
        perror("Nao pude abrir o arquivo de cadastro");
        return;
    }
    while (!feof(arquivo)) {
        struct funcionario var_local;
        if (fread(&var_local, sizeof(struct funcionario), 1, arquivo) < 1) {
            if (ferror(arquivo)) {
                perror("Erro ao ler novo registro");
                return;
            }
        } else {
            printf("Nome: %s; Horas trab: %.2f; Valor hr: R$ %.2f; Salario: R$ %.2f; Auxilio: R$ %.2f; Total: R$ %.2f\n",
                    var_local.nome, var_local.horas, var_local.valor_hr, var_local.salario_bruto, var_local.auxilio_alim,
                    var_local.salario_bruto + var_local.auxilio_alim);
        }
    }
    fclose(arquivo);
}

