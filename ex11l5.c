#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_STRING  50

void troca_minMAI(char [*]);

int main(void) {
    char string[MAX_STRING];

    puts("Digite uma frase abaixo:");
    gets(string);

    // Chama a funcao que vai trocar minusculas/MAIUSCULAS na frase
    troca_minMAI(string);   // um vetor (string) passado como parametro eh alterado pela funcao

    printf("Frase alterada: %s\n", string);

    return EXIT_SUCCESS;
}

void troca_minMAI(char s[]) {
    int pos = 0;
    while (s[pos]) { // enquanto s[pos] nao for 0 (term. nulo), ou seja, s[pos] for "verdadeiro"
        char c = s[pos];
        if (isalpha(c)) {       // se for letra...
            /*
            if (islower(c)) {   // ... e se for minusculo, ...
                c = toupper(c); // ... converte pra maiusculo
            }
            else {
                c = tolower(c); // senao, converte pra minusculo
            }
            */
            c = islower(c)? toupper(c): tolower(c);
            s[pos] = c; // salva o caracter transformado na string
        }
        ++pos;
    }
}

