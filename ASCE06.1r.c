#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Identificador usado pelo pre-processador para substituir por 9
// todas as ocorrencias de NUM_VALORES no codigo (desde que nao esteja
// entre aspas "" - ex. para uso num printf)
#define NUM_VALORES 9

// Outros exemplos nao relacionados ao programa...
#define PRIMEIRA_LETRA_DO_ALFABETO 'A'
#define PI 3.1416

int main(void) {
    // Vetor com nove numeros inteiros
    // const int NUM_VALORES = 9;
    int vetor[NUM_VALORES];

    // Para percorrer/atravessar um vetor, usa-se um
    // laco cuja variavel de controle acaba sendo a mesma
    // usada como indice
    int indice;
    for (indice = 0; indice < NUM_VALORES; ++indice) {
        printf("Digite o numero para a %da. posicao do vetor: ", indice+1);
        scanf("%d", &vetor[indice]); // faz referencia ao elemento da vez
    }

    // Percorre o vetor novamente, procurando por numeros primos...
    for (indice = 0; indice < NUM_VALORES; ++indice) {
        bool eh_primo = true; // considera de inicio que o numero pode ser primo
        int divisor = vetor[indice] - 1; // comeca a sequencia de divisores
                                         // com o numero imediatamente anterior
        while (divisor > 1) {
            if (vetor[indice] % divisor == 0) {
                // Encontrei um numero no caminho que divide o elemento
                // do vetor - ele NAO eh primo!
                eh_primo = false;
                break; // interrompe o while(), nao precisa continuar...
            }
            --divisor; // na repeticao do laco, usa um divisor menor
        }
        if (eh_primo == true) {
            printf("O numero %d eh primo e estah na %da. posicao (indice %d)\n",
                   vetor[indice], indice+1, indice);
        }
    }
    return EXIT_SUCCESS;
}

