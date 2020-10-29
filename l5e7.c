#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define INDICE_INVALIDO -1
#define TAMANHO_MAX_FRASE 100

int main(void) {
    char frase[TAMANHO_MAX_FRASE + 1]; // reserva um espaco adicional para o terminador nulo
    char caractere;

    puts("Digite uma frase abaixo:");
    gets(frase);

    printf("Digite um caractere a ser avaliado na frase: ");
    __fpurge(stdin); // em Linux; em Windows: fflush(stdin)
    caractere = getchar(); // le um caractere do teclado

    int ultima = INDICE_INVALIDO;
    unsigned ocorrencias = 0;
    int indice = strlen(frase); // inicia o indice na posicao do terminador nulo
    while (indice >= 0) {
        if (frase[indice] == caractere) {
            ++ocorrencias;
            if (ultima == INDICE_INVALIDO) {
                ultima = indice;
            }
        }
        --indice;
    }

    printf("O numero de ocorrencias do caractere '%c' em '%s' eh %u\n", caractere, frase, ocorrencias);
    printf("A ultima posicao (indice) desse caractere eh %d\n", ultima);

    return EXIT_SUCCESS;
}