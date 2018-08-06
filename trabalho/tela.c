#include <stdlib.h>
#include <stdio.h>
#include "trabalho.h"

void imprime_placa(void) {
    const char* clrcmd =
#ifdef WIN32
    "cls",
#else
    "clear",
#endif
    *moldura = "+----+----+----+----+";

    if (system(clrcmd) < 0) {
        puts("Erro de exibicao do jogo");
        exit(EXIT_FAILURE);
    }
    putchar('\n');
    int l, c;
    for (l=0; l<TAMANHO; ++l) {
        puts(moldura);
        for (c=0; c<TAMANHO; ++c) {
            if (placa_jogo[l][c] != 0) {
                printf("| %2d ", placa_jogo[l][c]);
            }
            else {
                printf("|    ");
            }
        }
        printf("|\n");
    }
    puts(moldura);
    putchar('\n');
}
