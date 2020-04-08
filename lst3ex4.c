#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned n; // variavel de entrada

    printf("Digite um numero: ");
    scanf("%u", &n);

    bool primo = true; // assumindo a hipotese do numero ser, sim, um primo

    unsigned inter;
    for (inter = n-1; inter > 1; --inter) {
        if (n % inter == 0) { // essa condicao deveria ser sempre falsa para
                              // um numero primo
            primo = false;
            break; // nao faz sentido continuar o laco ateh o final

            // Uma alternativa ao uso do 'break' seria mudar o 'for' para:
            // for (inter = n-1; inter > 1 && primo == true; --inter) {...
        }
    }

    if (primo == true) { // if (primo) {
        printf("O numero digitado por voce eh primo.\n");
    } else {
        printf("Voce digitou um numero que NAO eh primo.\n");
    }
    return EXIT_SUCCESS;
}

