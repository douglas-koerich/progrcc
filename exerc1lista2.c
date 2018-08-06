#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    char caractere;
    printf("Digite um caractere qualquer: ");
    scanf(" %c", &caractere); // macete: ponha o espaco em branco antes do %c

    if (isalpha(caractere) == false) { // verifica se NAO eh caractere
    // if (!isalpha(caractere)) { // maneira alternativa de testar
        printf("Outro\n");
    } else {
        // if (caractere == 'a' || caractere == 'A' || caractere == 'e' || ...
        caractere = tolower(caractere); // substitui a letra por sua minuscula
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' ||
            caractere == 'o' || caractere == 'u' || caractere == 'y') {
            printf("Vogal\n");
        } else {
            printf("Consoante\n");
        }
    }

    return EXIT_SUCCESS;
}

