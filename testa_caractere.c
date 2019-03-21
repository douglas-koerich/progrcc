#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> // para uso do isalpha()

int main() {
    char c;
    printf("Tecle algo (e digite <Enter>): ");
    scanf(" %c", &c);

    // se c for letra entao
    // if (isalpha(c) == true) {
    // if (isalpha(c) != 0) { // em C, diferente de zero num teste eh "verdadeiro"
    // if (isalpha(c)) {
    // if (c >= 'A' && <= 'Z') { <-- ISTO ESTAH ERRADO!!
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        // escreva "Eh uma letra"
        printf("Eh uma letra!\n");
        if (isupper(c)) {
            printf("... e eh Maiuscula!!\n");
        } else {
            printf("... e eh minuscula!\n");
        }
    }
    // senao
    // else (isdigit(c)) // <--- ISTO ESTAH ERRADO!!!
    else {
        // escreva "Nao eh uma letra"
        printf("NAO eh uma letra!\n");

        if (isdigit(c)) {
            printf("Eh um algarismo (decimal)!\n");
        }
        // ... nesses caso vamos omitir o "senao" (estrutura de decisao SIMPLES)
    }
    // fim-se

    return EXIT_SUCCESS;
}

