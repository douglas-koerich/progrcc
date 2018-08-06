#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 1000

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de argumentos");
        printf("Use: %s <nome-do-arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }
    /*
     * char nome_arquivo[MAX_NOME];
     * printf("Digite o nome do arquivo: ");
     * gets(nome_arquivo);
     * FILE* arquivo = fopen(nome_arquivo, "r");
     */
    FILE* arquivo = fopen(argv[1], "r");    // somente-leitura de arquivo texto
    if (arquivo == NULL) {
        // Algum erro aconteceu, usa perror para visualizar
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }
    printf("Arquivo aberto sob o handle %p.\n", arquivo);
    
    FILE* maiusc = fopen("maiusc.txt", "w");    // cria para somente-escrita de texto
    if (maiusc == NULL) {
        perror("Nao foi possivel criar novo arquivo");
        return EXIT_FAILURE;
    }
    
    /* Leitura por caractere
    char c = fgetc(arquivo);
    printf("O primeiro caractere lido do arquivo eh '%c'.\n", c);
    c = fgetc(arquivo);
    printf("O proximo caractere eh '%c'.\n", c);
    */

    /* Leitura por linha
    char linha[MAX];
    fgets(linha, MAX, arquivo);
    printf("A primeira linha do arquivo eh \"%s\".\n", linha);
    fgets(linha, sizeof(linha), arquivo);
    printf("A segunda eh \"%s\".\n", linha);
    */

    // Leitura do arquivo completo
    while (feof(arquivo) == false) {    // while (!feof(arquivo))
        /* Repete a leitura de uma linha, para todas as linhas...
        char linha[MAX];
        if (fgets(linha, MAX, arquivo) == NULL) {   // ou erro, ou fim do arquivo
            if (ferror(arquivo) == true) {  // if (ferror(arquivo))
                perror("Erro na leitura do arquivo");
                return EXIT_FAILURE;
            }
            // else /* fim do arquivo lido pelo fgets, faz nada (deixa para o feof fazer)
        } else {    // nem erro, nem fim de arquivo...
            printf("%s", linha);
        }
        */
        // Repete a leitura de um caractere, para todos os caracteres
        char c = fgetc(arquivo);    
        if (c == EOF) { // ou erro, ou fim do arquivo de verdade...
            if (ferror(arquivo) == true) { // foi por erro que veio o EOF
                perror("Erro na leitura do arquivo");
                return EXIT_FAILURE;
            }
        } else { // nao retornou EOF, c contem o caractere lido
            putchar(c); // exibe o caractere lido do arquivo na tela
            char C = toupper(c);    // converte para maiuscula
            if (fputc(C, maiusc) == EOF) { // EOF aqui indica soh erro mesmo...
                perror("Erro na escrita do arquivo");
                return EXIT_FAILURE;
            }
        }
    }

    fclose(arquivo);
    fclose(maiusc);

    return EXIT_SUCCESS;
}

