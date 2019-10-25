#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAM_STRING 128

void imprime_reversa(char [*]); // com o terminador nulo nao eh mais
                                // necessario passar o tamanho do vetor

int main(void) {
    char str1[TAM_STRING] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char str2[TAM_STRING] = "Hell";

    int ret = strcmp(str1, str2);
    if (ret == 0) { // if (str1 == str2)
        puts("As strings sao iguais");
    } else {
        printf("As strings sao diferentes (ret = %d)\n", ret);
    }

    // Imprimindo as strings de forma inversa
    imprime_reversa(str1); putchar('\n'); // pra separar da proxima
    imprime_reversa(str2); putchar('\n'); // pra separar do prompt na
                                          // saida do programa

    return EXIT_SUCCESS;
}

void imprime_reversa(char string[]) {
    int posicao = strlen(string); // comeca no indice do '\0' no vetor
    // No inicio do laco, move para a posicao do ultimo caractere
    // que eh anterior ah posicao do terminador nulo
    for (--posicao; posicao >= 0; --posicao) { // soh o segundo "--posicao" repete!
        putchar(string[posicao]);
    }
}

