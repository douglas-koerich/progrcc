#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    char genero;

    do {
        printf("Ola, usuari@, digite o seu genero (M/F/X): ");
        scanf(" %c", &genero);
        genero = toupper(genero); // converte pra maius, se necessario
    } while (genero != 'M' && genero != 'F' && genero != 'X');

    if (genero == 'M') {
        printf("Bem-vindo ao nosso programa!\n");
    } else if (genero == 'F') {
        printf("Bem-vinda ao nosso programa, eh um prazer te-la conosco!\n");
    } else {
        printf("Bem-vindx ao nosso programa, aproveite!\n");
    }
    return EXIT_SUCCESS;
}

