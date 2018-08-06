#include <stdlib.h>
#include <stdio.h>
#ifndef WIN32           // se NAO estiver compilando em Windows...
#include <stdio_ext.h>  // necessario para __fpurge() - em Linux
#endif
#include "mygets.h"

#define MAX_STRING  20

size_t num_ocorrencias(char [*], char); // tamanho do vetor passado eh dispensavel
                                        // porque existe um marcador do fim util do mesmo

int main(void) {
    char var[MAX_STRING+1], c;

    printf("Digite uma palavra: ");
    Gets(var, MAX_STRING+1);
    printf("Digite um caractere: ");
#ifdef WIN32
    fflush(stdin);
#else
    __fpurge(stdin);
#endif
    c = getchar();  // le um caractere do teclado

    // Chama uma funcao para contar quantas vezes o caractere eh
    // encontrado na string
    size_t n = num_ocorrencias(var, c);

    printf("O numero de vezes que %c aparece em %s eh %zd.\n", c, var, n);

    return EXIT_SUCCESS;
}

size_t num_ocorrencias(char string[], char ch) {
    int i;
    size_t num;

    for (i = 0, num = 0; string[i] != '\0'; ++i) {
        if (string[i] == ch) {
            ++num;
        }
    }
    return num;
}

