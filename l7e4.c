#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "l7e4.h"

#define MAX_ORDENS_SERVICO 20
#define NOME_ARQUIVO_CADASTRO "/tmp/cadastro.bin"

int main(void) {
    // OrdemServico lista[MAX_ORDENS_SERVICO];
    OrdemServico* lista = malloc(MAX_ORDENS_SERVICO * sizeof(OrdemServico));

    int ordens = 0;
    while (ordens < MAX_ORDENS_SERVICO) {
        int numero_os;
        printf("Digite o numero da OS, ou 0 para encerrar: ");
        scanf("%d", &numero_os);
        if (numero_os <= 0) {
            break;
        }
        lista[ordens].numero = numero_os;
        puts("Informe a data da OS:");
        printf("Dia? ");
        scanf("%d", &lista[ordens].data.dia);
        printf("Mes? ");
        scanf("%d", &lista[ordens].data.mes);
        printf("Ano? ");
        scanf("%d", &lista[ordens].data.ano);
        printf("Digite o valor da OS: ");
        scanf("%f", &lista[ordens].valor);
        printf("Descreva o servico realizado: ");
        __fpurge(stdin); // "limpeza" da entrada do console (teclado)
        gets(lista[ordens].descricao);
        printf("Informe o nome do(a) cliente: ");
        __fpurge(stdin);
        gets(lista[ordens].cliente);

        ++ordens;

        if (ordens == MAX_ORDENS_SERVICO) {
            puts("Alcancou o limite maximo de OSs para cadastro");
        }
    }

    grava_banco_dados(lista, ordens);

    // Nao ocupa a memoria com o cadastro de OSs alem do necessario, agora ele jah
    // estah salvo no arquivo
    free(lista);

    calcula_estatisticas();

    return EXIT_SUCCESS;
}

void grava_banco_dados(const OrdemServico lista[], size_t comprimento) {
    FILE* arquivo = fopen(NOME_ARQUIVO_CADASTRO, "wb");
    if (arquivo == NULL) {
        perror("Nao foi possivel salvar o banco de dados");
        return;
    }
    /*
    int o;
    for (o = 0; o < comprimento; ++o) {
        if (fwrite(&lista[o], sizeof(OrdemServico), 1, arquivo) < 1) {
            perror("Erro ao salvar um registro no arquivo");
            break;
        }
    }
    */
    if (fwrite(lista, sizeof(OrdemServico), comprimento, arquivo) < comprimento) {
        perror("Erro ao salvar o banco de dados completo no arquivo");
    }
    fclose(arquivo);
}

void calcula_estatisticas(void) {
    FILE* arquivo = fopen(NOME_ARQUIVO_CADASTRO, "rb");
    if (arquivo == NULL) {
        perror("Nao foi possivel abrir o arquivo com o banco de dados");
        return;
    }
    size_t qtde_os = 0;
    float total_valores = 0.0, maior_valor;
    char nome_cliente_maior_valor[TAMANHO_CLIENTE];
    char descricao_maior_valor[TAMANHO_DESCRICAO];
    Data data_OS_maior_valor;

    while (!feof(arquivo)) {
        OrdemServico os; // variavel local para armazenar cada registro (OS) lido do arquivo
        if (fread(&os, sizeof(OrdemServico), 1, arquivo) < 1) {
            if (ferror(arquivo)) {
                perror("Erro ao ler um registro do arquivo");
                fclose(arquivo);
                return;
            }
        } else {
            if (qtde_os == 0 || maior_valor < os.valor) {
                maior_valor = os.valor;
                strcpy(nome_cliente_maior_valor, os.cliente);
                strcpy(descricao_maior_valor, os.descricao);
                data_OS_maior_valor = os.data; // copia campo por campo da estrutura Data
            }
            total_valores += os.valor;
            ++qtde_os;
        }
    }
    
    fclose(arquivo);

    printf("Media dos valores das OS: R$ %.2f\n", total_valores / qtde_os);
    puts("Dados da OS de maior valor:");
    printf("Valor: R$ %.2f\n", maior_valor);
    printf("Descricao: %s\n", descricao_maior_valor);
    printf("Data de execucao: %02d/%02d/%d\n", data_OS_maior_valor.dia, data_OS_maior_valor.mes,
           data_OS_maior_valor.ano);
    printf("Cliente: %s\n", nome_cliente_maior_valor);
}