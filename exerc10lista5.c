#include <stdbool.h> // tipo bool e constantes true/false
#include <stdlib.h>
#include <stdio.h>
#include <string.h> // funcoes strXXX()

// Prototipo da funcao
bool eh_palindroma(char [*]); // nao eh necessario informar o tamanho por parametro

int main(void) {
    char string1[] = "Arara";
    char string2[] = "arara";

    bool ok = eh_palindroma(string1);
    if (ok == true) {
        printf("'%s' eh palindroma!\n", string1);
    } else {
        printf("'%s' NAO eh palindroma!\n", string1);
    }

    ok = eh_palindroma(string2);
    if (ok == true) {
        printf("'%s' eh palindroma!\n", string2);
    } else {
        printf("'%s' NAO eh palindroma!\n", string2);
    }
    return EXIT_SUCCESS;
}

bool eh_palindroma(char str[]) {
    /* Versao 1:
    char invertida[strlen(str)+1]; // +1 para o \0 da copia
    int cresc, decresc;
    for (cresc = 0, decresc = strlen(str)-1; // ultimo caractere estah no indice strlen()-1
         str[cresc] != '\0'; ++cresc, --decresc) {
        invertida[cresc] = str[decresc];
    }
    invertida[cresc] = '\0';    // indice 'cresc' parou de incrementar quando achou o \0
    return strcmp(str, invertida) == 0; // retorna true se for igual a 0
    */

    // Versao 2:
    int cresc = 0, decresc = strlen(str) - 1; // ultimo caractere estah no indice strlen()-1
    while (cresc < decresc) {
        if (str[cresc] != str[decresc]) {
            return false;
        }
        ++cresc, --decresc;
    }
    return true;
}


