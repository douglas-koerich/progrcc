#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_FRASE 1000

int main(void) {
    // Leitura da frase
    char frase[MAX_FRASE];
    puts("Digite abaixo a sua frase:");
    gets(frase);
    /*
    fgets(frase, sizeof(frase), stdin); // inconveniente de trazer tambem o \n
    */

    // Leitura do caractere
    char ch;
    printf("Digite o caractere: ");
    scanf(" %c", &ch);

    // Letra (a): contador do caractere
    unsigned contador = 0;
    int i;
    for (i=0; frase[i] != '\0'; ++i) {
        if (frase[i] == ch) {
            ++contador;
        }
    }
    printf("O caractere %c ocorre %u vezes na frase '%s'.\n", ch, contador, frase);

    // Letra (b): ultima ocorrencia
    i = strlen(frase) - 1;
    while (i >= 0) {
        if (frase[i] == ch) {
            break;
        }
        --i;
    }
    printf("%sEncontrado na posicao (indice) %d.\n", (i<0? "NAO ": ""), i);
    return EXIT_SUCCESS;
}

