#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_NOME_CIDADE 32
#define NOME_ARQUIVO "/tmp/cidades.txt"

int main(void) {
    char rascunho[MAX_NOME_CIDADE];
    
    FILE* arquivo = fopen(NOME_ARQUIVO, "w");
    if (arquivo == NULL) {
        perror("Erro na criacao do arquivo");
        return EXIT_FAILURE;
    }
    
    size_t tamanho;
    do {
        printf("Digite o nome de uma cidade: ");
        __fpurge(stdin); // fflush(stdin);
        gets(rascunho);
        tamanho = strlen(rascunho);
        if (tamanho > 0) {
            // Uma vez que fputs NAO poe um \n no fim da string ao
            // grava-la no arquivo, vamos concatenar esse caractere na
            // mesma
            strcat(rascunho, "\n");
            if (fputs(rascunho, arquivo) == EOF) {
                perror("Erro na escrita do arquivo");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
            /*
            // Alternativamente a solucao acima, poderiamos ter gravado
            // o \n diretamente no arquivo apos a string
            if (fputc('\n', arquivo) == EOF) {
                ...
            }
            */
        }
    } while (tamanho > 0);
    
    fclose(arquivo);

    int num;
    printf("Forneca o numero da cidade que deseja ler do arquivo: ");
    scanf("%d", &num);

    arquivo = fopen(NOME_ARQUIVO, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }
    int cont = 0;
    while (!feof(arquivo) && cont < num-1) { // Le as linhas anteriores
        if (fgets(rascunho, MAX_NOME_CIDADE, arquivo) == NULL) {
            if (ferror(arquivo)) {
                perror("Erro ao ler o arquivo");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
        } else {
            ++cont; // mais um \n lido
        }
    }
    // A esta altura, estaremos prestes a ler a proxima linha (num)
    if (!feof(arquivo) && // vai que num seja maior que o arquivo...
        fgets(rascunho, MAX_NOME_CIDADE, arquivo) == NULL) {
        if (ferror(arquivo)) {
            perror("Erro ao ler a cidade desejada");
            fclose(arquivo);
            return EXIT_FAILURE;
        }
    } else {
        printf("A cidade na linha %d eh %s\n", num, rascunho);
    }

    fclose(arquivo);

    return EXIT_SUCCESS;
}

