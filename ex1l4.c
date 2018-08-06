#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>    // pra usar o tipo booleano, do contrario teria que usar int

bool ehPrimo(int);

int main(void) {
    int numero;
    printf("Digite um numero para teste: ");
    scanf("%d", &numero);

    if (ehPrimo(numero) == true) {
        printf("O numero %d eh primo!\n", numero);
    }
    else {
        printf("O numero %d NAO eh primo!\n", numero);
    }
    return EXIT_SUCCESS;
}

bool ehPrimo(int x) {
    int i;
    for (i=1; i<=x; ++i) {
        if (x % i == 0) {   // O numero informado por parametro eh divisivel por um numero dentro da faixa?
            if (i != 1 && i != x) { // Eh um numero no meio da faixa? Entao o numero nao eh primo!
                return false;   // SAI DA FUNCAO AQUI MESMO, AINDA QUE NAO TENHA TERMINADO O LACO!!!
            }
        }
        // Nao existe 'else' aqui, nao faz nada se NAO for divisivel, apenas vai para o proximo 'i'
    }
    // Se concluiu o laco sem encontrar um divisor, entao o numero eh primo
    return true;
}

