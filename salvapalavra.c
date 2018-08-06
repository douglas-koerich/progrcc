#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_TAM_PALAVRA 40

int main(void) {
    char palavra[MAX_TAM_PALAVRA];
    bool fim = false;
    FILE* arquivo = fopen("palavras.txt", "w+");
    if (arquivo == NULL) {
        perror("Nao pude criar o arquivo");
        return EXIT_FAILURE;
    }
    do {
        printf("Nova palavra (. para encerrar): ");
        scanf(" %s", palavra);
        if (strlen(palavra) == 1 && palavra[0] == '.') {
            fim = true;
        } else {
            char inicial = toupper(palavra[0]);
            if (inicial != 'A' && inicial != 'E' && inicial != 'I' &&
                inicial != 'O' && inicial != 'U' && inicial != 'Y') {
                if (fputs(palavra, arquivo) == EOF || fputc('\n', arquivo) == EOF) {
                    perror("Nao pude escrever no arquivo");
                    return EXIT_FAILURE;
                }
            }
        }
    } while (!fim);

    // Volta ao inicio do arquivo ("rebobina"/rewind do videocassete)
    rewind(arquivo);
/*
    fclose(arquivo);
    arquivo = fopen("palavras.txt", "r");
    if (arquivo == NULL) {
        perror("Nao pude abrir o arquivo");
        return EXIT_FAILURE;
    }
*/
    int contador = 0;
    while (!feof(arquivo)) {
        char caractere = fgetc(arquivo);
        if (caractere == EOF) {
            if (ferror(arquivo)) {
                perror("Nao pude ler do arquivo");
                return EXIT_FAILURE;
            }
        } else {
            if (isalpha(caractere)) {
                caractere = toupper(caractere);
                if (caractere != 'A' && caractere != 'E' && caractere != 'I' &&
                    caractere != 'O' && caractere != 'U' && caractere != 'Y') {
                    ++contador;
                }
            }
        }
    }
    printf("Foram encontradas %d consoantes no arquivo.\n", contador);
    fclose(arquivo);

    return EXIT_SUCCESS;
}
