#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_STRING  50

void troca_minMAI(char*);

int main(void) {
    char string[MAX_STRING];

    puts("Digite uma frase abaixo:");
    gets(string);   // O nome do vetor eh o endereco do seu primeiro elemento/caracter

    // Chama a funcao que vai trocar minusculas/MAIUSCULAS na frase
    troca_minMAI(string);   // um vetor (string) passado como parametro eh alterado pela funcao

    printf("Frase alterada: %s\n", string);

    return EXIT_SUCCESS;
}

void troca_minMAI(char* s) {
    while (*s != '\0') {
        if (isalpha(*s)) {       // se for letra...
            /*
            if (islower(*s)) {   // ... e se for minusculo, ...
                *s = toupper(*s); // ... converte pra maiusculo
            }
            else {
                *s = tolower(*s); // senao, converte pra minusculo
            }
            */
            *s = islower(*s)? toupper(*s): tolower(*s);
        }
        ++s;
    }
}

