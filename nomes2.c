#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_NOME_CIDADE 32
#define NOME_ARQUIVO "/tmp/cidades.bin"

int main(void) {
    char rascunho[MAX_NOME_CIDADE];
    
    FILE* arquivo = fopen(NOME_ARQUIVO, "wb");
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
            if (fwrite(rascunho, sizeof(char), MAX_NOME_CIDADE, arquivo)
                == EOF) {
                perror("Erro na escrita do arquivo");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
        }
    } while (tamanho > 0);
    
    fclose(arquivo);

    int num;
    printf("Forneca o numero da cidade que deseja ler do arquivo: ");
    scanf("%d", &num);

    arquivo = fopen(NOME_ARQUIVO, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }
    int retorno = fseek(arquivo, (num-1)*MAX_NOME_CIDADE, SEEK_SET);
    //            >> salta os num-1 vetores salvos anteriormente
    if (retorno == -1) {
        perror("Erro ao saltar no arquivo");
        fclose(arquivo);
        return EXIT_FAILURE;
    }
    // A esta altura, estaremos prestes a ler o proximo vetor (num)
    if (!feof(arquivo) && // vai que num seja maior que o arquivo...
        fread(rascunho, sizeof(char), MAX_NOME_CIDADE, arquivo) < MAX_NOME_CIDADE) {
        if (ferror(arquivo)) {
            perror("Erro ao ler a cidade desejada");
            fclose(arquivo);
            return EXIT_FAILURE;
        }
    } else {
        printf("A cidade na linha %d eh %s\n", num, rascunho);
    }

    // Imprimindo o nome da ULTIMA cidade gravada
    if (fseek(arquivo, -(MAX_NOME_CIDADE), SEEK_END) == -1) {
        perror("Erro ao buscar o ultimo vetor");
        fclose(arquivo);
        return EXIT_FAILURE;
    }
    if (fread(rascunho, sizeof(char), MAX_NOME_CIDADE, arquivo) <
        MAX_NOME_CIDADE) {
        perror("Erro ao ler o ultimo vetor");
        fclose(arquivo);
        return EXIT_FAILURE;
    }
    printf("A ultima cidade gravada eh %s\n", rascunho);

    fclose(arquivo);

    return EXIT_SUCCESS;
}

