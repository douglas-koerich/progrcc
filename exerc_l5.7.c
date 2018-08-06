#include <stdlib.h>
#include <stdio.h>
#if !defined WIN32 && !defined WIN64
#define __FPURGE        // cria uma "marca" de estar em Linux usando __fpurge
#include <stdio_ext.h>  // cabecalho exclusivo do Linux
#endif
#include <string.h>

#define MAX_FRASE 200

int main(void) {
    char frase[MAX_FRASE+1];
    char caractere;

    puts("Digite uma frase abaixo: ");
    gets(frase);

    printf("Digite um caractere para busca: ");
#ifndef __FPURGE
    fflush(stdin);  // Windows
#else
    __fpurge(stdin);    // "limpa" o buffer do teclado (remove <Enter>)
#endif
    caractere = getchar();

    // Letra (a)
    unsigned contador = 0;
    int i = 0;
    while (frase[i] != '\0') {
        if (frase[i] == caractere) { // verifica se eh o caractere procurado
            ++contador;
        }
        ++i;    // vai ao proximo caractere da string
    }
    printf("O caractere %c foi encontrado %u vezes.\n", caractere, contador);

    // Letra (b)
    i = strlen(frase) - 1;  // strlen() calcula o comprimento da string,
                            // e indiretamente descobre a posicao de \0
                            // -1 significa a posicao do ultimo caractere
                            // valido
    while (i >= 0) {    // enquanto nao passar do inicio da string...
        if (frase[i] == caractere) {
            break;      // achei o ultimo, interrompe o laco
        }
        --i;            // nao achei, continuo para tras...
    }
    if (i >= 0) {
        printf("Encontrei o caractere na posicao %d.\n", i);
    } else {
        printf("Caractere nao encontrado! (%d invalido).\n", i);
    }
    return EXIT_SUCCESS;
}

