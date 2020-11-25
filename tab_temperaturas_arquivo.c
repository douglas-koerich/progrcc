#include <stdlib.h>
#include <stdio.h>

/*
#define NUM_LINHAS 7
#define NUM_COLUNAS 3
*/

int main(void) {
    const size_t NUM_LINHAS = 7, NUM_COLUNAS = 3;
    int tabela[NUM_LINHAS][NUM_COLUNAS];

    // const char* const
    // ^     ^     ^
    // |     |     O(s) ponteiro(s) nao podem receber outro endereco (ponteiro constante)
    // |      O tipo do dado apontado pelo ponteiro eh um (conjunto de) char -> string
    // O conteudo da posicao enderecada pelo ponteiro nao pode ser mudado pelo operador * dele
    const char* const NOMES_DIAS[] = { "Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab" };

    /* Forma alternativa
    const char NOMES_DIAS[][4] = { "Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab" };
    */

    int dia;
    for (dia = 0; dia < NUM_LINHAS; ++dia) {
        int medida;
        printf("Digite as temperaturas medidas no(a) %s:\n", NOMES_DIAS[dia]);
        for (medida = 0; medida < NUM_COLUNAS; ++medida) {
            printf("Medida #%d: ", medida + 1);
            scanf("%d", &tabela[dia][medida]);
        }
    }

    // Cria um arquivo-texto para armazenar a tabela no mesmo
    FILE* arquivo = fopen("/tmp/exemplo.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao criar arquivo de saida");
        return EXIT_FAILURE;
    }

    fputs("DIA,#1,#2,#3,Media\n", arquivo);
    for (dia = 0; dia < NUM_LINHAS; ++dia) {
        int medida, soma = 0;
        fprintf(arquivo, "%s,", NOMES_DIAS[dia]);
        for (medida = 0; medida < NUM_COLUNAS; ++medida) {
            fprintf(arquivo, "%2d,", tabela[dia][medida]);
            soma += tabela[dia][medida];
        }
        fprintf(arquivo, "%5.1f\n", (float) soma / NUM_COLUNAS); // deve forcar divisao real!
    }

    fclose(arquivo);

    // Cria um arquivo-binario para armazenar a mesma tabela no seu formato original de dados
    arquivo = fopen("/tmp/exemplo.dat", "wb");
    if (arquivo == NULL) {
        perror("Erro ao criar arquivo binario de saida");
        return EXIT_FAILURE;
    }

    for (dia = 0; dia < NUM_LINHAS; ++dia) {
        int medida, soma = 0;
        for (medida = 0; medida < NUM_COLUNAS; ++medida) {
            // fwrite(&tabela[dia][medida], sizeof(int), 1, arquivo);
            soma += tabela[dia][medida];
        }        
        float media = (float) soma / NUM_COLUNAS;
        fwrite(&tabela[dia][0], sizeof(int), NUM_COLUNAS, arquivo); // grava a linha inteira de uma vez
        fwrite(&media, sizeof(float), 1, arquivo);
    }

    fclose(arquivo);

    return EXIT_SUCCESS;
}