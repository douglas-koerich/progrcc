#include <stdlib.h>
#include <stdio.h>
#include <string.h> // talvez nao seja necessario...
#include <ctype.h>

void invminmai(char [*]); // nao retorna nada porque a alteracao eh
                          // feita sobre a propria string (que eh um
                          // vetor, portanto a funcao pode altera-lo)

#define MAX_CARACTERES 1000

int main(void) {
    char frase[MAX_CARACTERES];

    puts("Digite uma frase abaixo:");
    gets(frase); // leh todos os caracteres ateh um salto de linha

    invminmai(frase); // passa o vetor (string) para a funcao

    puts("Frase convertida:");
    puts(frase); // puts() pode ser usada para imprimir variavel-string

    return EXIT_SUCCESS;
}

void invminmai(char s[]) {
    int i = 0;
    while (s[i] != '\0') { // enquanto nao achar o terminador nulo...
        if (isalpha(s[i])) { // avalia elemento a elemento do vetor
            if (isupper(s[i])) { // eh maiuscula?
                s[i] = tolower(s[i]); // recebe o minusculo de si mesmo
            } else {
                s[i] = toupper(s[i]); // maiusculo de si mesmo
            }
        }
        ++i;
    }
}
