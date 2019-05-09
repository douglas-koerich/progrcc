#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

#define TAMANHO 50

int main(void) {
    char frase[TAMANHO], caractere;

    printf("Digite um caractere: ");
    caractere = getchar(); // uso do getchar() ao inves do scanf com %c

    puts("Agora, digite uma frase:");
    // Como gets() nao tem " %s" pra incluir o espaco, pra limpar o \n
    // do getchar() eh preciso chamar __fpurge antes
    __fpurge(stdin);
    gets(frase);

    int local, i;
    unsigned contador;
    for (i=0, local=-1, contador=0; frase[i] != '\0'; ++i) {
        if (frase[i] == caractere) {
            ++contador;
            local = i;
        }
    }

    printf("O caractere %c foi encontrado %u vezes na frase\n"
           "%s, sendo a ultima posicao a %d.\n", caractere, contador,
           frase, local+1); 

    return EXIT_SUCCESS;
}

