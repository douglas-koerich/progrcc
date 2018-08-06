#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mygets.h"

#ifndef WIN32
#include <stdio_ext.h>
#endif

#define MAX_STRING  100

int busca_reversa(char [*], char);

int main(void) {
    printf("Digite uma palavra ou frase: ");
    char string[MAX_STRING+1];
    Gets(string, sizeof(string));

    // Limpa o espacamento deixado pela string acima, se houver
#ifdef WIN32
    fflush(stdin);
#else
    __fpurge(stdin);
#endif

    printf("Digite um caractere para ser buscado na mesma: ");
    char c = getchar();

    int pos = busca_reversa(string, c);

    if (pos == -1) {
        printf("O caractere %c nao foi encontrado em '%s'.\n", c, string);
    } else {
        printf("Encontrei %c no indice %d de '%s'.\n", c, pos, string);
    }
    return EXIT_SUCCESS;
}

int busca_reversa(char s[], char c) {
    int i = strlen(s); // Usa strlen() pra descobrir o ultimo indice (do '\0)
    while (i >= 0) {
        if (s[i] == c) {
            return i;
        }
        --i;
    }
    return -1;  // return i; (jah que se eu cheguei aqui eh porque i == -1)
}

