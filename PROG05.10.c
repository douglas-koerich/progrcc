#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX_STRING 40

bool testa_palindroma(const char [*]); // const para nao alterar o conteudo

int main(void) {
    char entrada[TAM_MAX_STRING];
    printf("Digite a palavra a ser verificada: ");
    scanf(" %s", entrada); // funciona apenas para palavras, nao frases com espacos

    if (testa_palindroma(entrada)) {
        puts("A palavra eh palindroma");
    } else {
        puts("A palavra NAO eh palindroma");
    }
    return EXIT_SUCCESS;
}

bool testa_palindroma(const char str[]) {
    // Dois indices, o primeiro no inicio da string...
    int i = 0;

    // ... e o segundo, no ultimo caractere valido
    int j = strlen(str) - 1; // posicao anterior ao \0

    while (str[i] != '\0') {
        // Se na "leitura" (varredura) indo da esquerda para a direita (com i)
        // e da direita para a esquerda (com j), houver diferenca entre eles...
        if (tolower(str[i]) != tolower(str[j])) { // ignorar MAI/min
            return false;
        }
        ++i, --j;
    }
    return true; // terminei toda a varredura sem encontrar diferenca na
                 // "leitura" nos dois sentidos!
}

