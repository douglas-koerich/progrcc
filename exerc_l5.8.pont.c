#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char cripto_char(char); // funcao auxiliar de criptografa()
void criptografa(char*);

#define TAM_STRING 50

int main(void) {
    char* string = malloc(TAM_STRING);
    puts("Digite uma frase abaixo: ");
    gets(string);

    criptografa(string);

    puts("Frase criptografada:");
    puts(string);

    free(string);
    return EXIT_SUCCESS;
}

char cripto_char(char c) {
    if (!isalpha(c)) {
        return c;
    }
    char mai = toupper(c); // pra nao comparar maiusculas E minusculas
    if (mai == 'A' || mai == 'E' || mai == 'I' || mai == 'O' || mai == 'U' ||
        mai == 'Y') {
        return c;
    }
    return '#';
}

void criptografa(char* str) {
    int esq = 0, dir = strlen(str)-1; // indice final obtido de forma indireta
                                      // pelo tamanho da string
    while (esq <= dir) {
        char aux = cripto_char(*(str+esq));
        *(str+esq) = cripto_char(*(str+dir));
        *(str+dir) = aux;
        ++esq, --dir;
    }
}

