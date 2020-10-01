#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool testa_primo(unsigned);

int main(void) {
    unsigned n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%u", &n);

    // Chama a funcao que verifica se o numero eh primo
    bool eh_Primo = testa_primo(n);

    if (eh_Primo) {
        printf("O numero eh primo!\n");
    } else {
        printf("O numero NAO eh primo!\n");
    }
    return EXIT_SUCCESS;
}

bool testa_primo(unsigned numero) {
    unsigned divisor = 2;

    // Simplificamos o algoritmo desenvolvido para o exercicio #4 da lista #3
    while (divisor <= numero / 2) {
        if (numero % divisor == 0) {
            return false;
        } 
        ++divisor;
    }
    return true;
}
