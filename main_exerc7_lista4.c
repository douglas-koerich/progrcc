#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//if !defined WINDOWS
#ifndef WINDOWS
#include <stdio_ext.h> // __fpurge; este cabecalho soh existe em Linux!
#endif

// float calcula_media(float, float, float, char);
#include "func_exerc7_lista4.h" // inclusao do cabecalho particular do programa

int main(void) {
    float nota1, nota2, nota3;
    char letra;

    printf("Digite a nota #1: "); scanf("%f", &nota1);
    printf("Digite a nota #2: "); scanf("%f", &nota2);
    printf("Digite a nota #3: "); scanf("%f", &nota3);

    do {
        printf("Digite o tipo da media: ");
        /*
        scanf(" %c", &letra); // espaco-em-branco antes do %c para
                              // "limpar" a entrada do(s) scanf(s) anterior(es)
        */
//#if defined WINDOWS
#ifdef WINDOWS
        fflush(stdin); // WINDOWS: "limpa" a entrada do(s) scanf(s) anterior(es)
#else
        __fpurge(stdin); // LINUX: "limpa" a entrada do(s) scanf(s) anterior(es)
#endif
        scanf("%c", &letra);

        letra = toupper(letra); // salva em _letra_ a MAIUSCULA de _letra_
    } while (letra != 'A' && letra != 'P');

    float media;
    media = calcula_media(nota1, nota2, nota3, letra);

    printf("A media calculada eh %.1f.\n", media);

    return EXIT_SUCCESS;
}

