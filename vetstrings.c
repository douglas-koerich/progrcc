#include <stdlib.h>
#include <stdio.h>

#define TAM_MAX_NOME 50 // define o numero de colunas
#define NUM_NOMES 5 // define o numero de linhas

int main(void) {
    // Um vetor de strings eh, na verdade, representado/implementado
    // por uma matriz de caracteres, onde cada linha da matriz eh uma
    // string individual
    char lista_nomes[NUM_NOMES][TAM_MAX_NOME];

    // Vou percorrer o "vetor" de strings com um unico laco
    int i;
    for (i = 0; i < NUM_NOMES; ++i) {
        printf("Digite o %do. nome: ", i+1);
        gets(lista_nomes[i]); // apenas o primeiro indice!
    }

    // Imprime o primeiro e o ultimo nome
    printf("Primeiro: %s\n", lista_nomes[0]);
    printf("Ultimo: %s\n", lista_nomes[NUM_NOMES-1]);

    return EXIT_SUCCESS;
}

