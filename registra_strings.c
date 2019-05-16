#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_STRING 1024

/* Este programa salva num arquivo todas as strings/linhas
 * digitadas no console.
 */

int main(void) {
    char entrada[MAX_STRING];
    FILE* arquivo = fopen("/tmp/string.log", "a");
    if (arquivo == 0) {
        perror("Nao foi possivel criar o arquivo de registros");
        return EXIT_FAILURE;
    }
    puts("Digite algumas linhas de texto abaixo (vazia para concluir):");
    size_t tamanho;
    do {
        __fpurge(stdin);
        gets(entrada); // o '\n' digitado nao vem com a string, eh substituido
                       // por '\0'
        tamanho = strlen(entrada);
        if (tamanho > 0) {
            strcat(entrada, "\n"); // poe o '\n' que o fputs nao poe...
            if (fputs(entrada, arquivo) == EOF) { // fputs nao poe um '\n' no final
                perror("Nao foi possivel escrever a string no arquivo");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
        }
    } while (tamanho > 0);
    fclose(arquivo);
    return EXIT_SUCCESS;
}

