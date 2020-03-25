#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    printf("Por favor, digite um caractere: ");
    scanf("%c", &ch);

    // Converte o caractere para sua versao maiuscula
    ch = toupper(ch);

    // Distincao entre o que eh letra e outros simbolos
    if (isalpha(ch)) {
        // Bloco de codigo para tratar o caso das letras
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            printf("Vogal\n");
        } else {
            printf("Consoante\n");
        }
    } else {
        // Todos os outros simbolos (algarismos, pontuacao, etc.)
        printf("Outro\n");
    } 
    return EXIT_SUCCESS;
}

