#include <stdlib.h>
#include <stdio.h>
#ifdef LINUX // se estiver definido 'LINUX' na linha/no comando de compilacao
#include <stdio_ext.h> // para __fpurge()
#endif
#include <ctype.h>
#include "combinatoria.h"

int main(void) {
    printf("Digite n: ");
    int n;
    scanf("%d", &n);
    printf("Digite p: ");
    int p;
    scanf("%d", &p);

    char opcao;
    do {
        printf("(A)rranjo ou (C)ombinacao? ");
#ifndef LINUX
        fflush(stdin);      // le o buffer do teclado no Windows
#else
        __fpurge(stdin);    // le o buffer do teclado no Linux
#endif
        scanf("%c", &opcao);
        opcao = tolower(opcao);
    } while (opcao != 'a' && opcao != 'c');

    printf("P(%d) = %d\n", n, permutacao(n));
    if (opcao == 'a') {
        printf("A(%d, %d) = %d\n", n, p, arranjo(n, p));
    } else {
        printf("C(%d, %d) = %d\n", n, p, combinacao(n, p));
    }
    return EXIT_SUCCESS;
}

