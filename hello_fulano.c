#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NOME 1024

int main(int argc, char* argv[]) {
    char nome[MAX_NOME] = "Anonimo(a)"; // variavel string inicializada

    if (argc >= 2) {
        strcpy(nome, argv[1]); // usa segundo parametro de main() como nome
    }
    printf("Ola, %s!\n", nome);

    return EXIT_SUCCESS;
}

