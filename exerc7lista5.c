#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

#define MAX_TAM_FRASE  500

int main(void) {
    char frase[MAX_TAM_FRASE];
    char caractere;

    printf("Digite uma frase qualquer: ");
    gets(frase);

    printf("Digite agora um caractere qualquer: ");
    __fpurge(stdin); // remove o '\n' remanescente do gets() anterior
    caractere = getchar();

    /* letras a e b no mesmo laco */
    unsigned cont = 0;
    int indice = 0, ultimo = -1;    // 'ultimo' inicia com um indice "invalido"
    while (frase[indice] != '\0') { // enquanto nao encontrar o fim da string...
        if (frase[indice] == caractere) {
            ultimo = indice;    // lembra qual foi o ultimo
            ++cont;
        }
        ++indice;
    }
    if (ultimo != -1) {
        printf("O caractere %c foi encontrado %u vezes na frase (ultimo indice = %d)\n",
               caractere, cont, ultimo);
    } else {
        puts("Caractere nao encontrado na frase!");
    }
    return EXIT_SUCCESS;
}

