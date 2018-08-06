#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned num;
    do {
        printf("Digite um numero positivo nao-nulo: ");
        scanf("%u", &num);
    } while (num == 0);

    bool eh_primo = true;   // hipotese inicial: EH PRIMO
    unsigned divisor = 2;   // primeiro numero que pode invalidar a hipotese
    while (divisor < num) {  // ateh o numero imediatamente anterior
        if (num % divisor == 0) {
            // Existe um intermediario que dividiu o numero
            eh_primo = false;
            break;
        }
        ++divisor;  // proximo intermediario pra testar
    }
    if (eh_primo) {
        printf("Numero eh primo!\n");
    } else {
        printf("Numero NAO eh primo!\n");
    }
    return EXIT_SUCCESS;
}

