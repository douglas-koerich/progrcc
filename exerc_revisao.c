/* Elabore uma funcao em linguagem C que receba um numero inteiro e
 * positivo e o decomponha em fatores primos, escrevendo na tela o
 * resultado da sua decomposicao. Por exemplo, dado o numero 150, a
 * funcao imprimiria 2 * 3 * 5^2
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void decompoe(unsigned);    // procedimento (sem retorno)
bool eh_primo(unsigned);

int main(void) {
    unsigned numero;
    printf("Digite um numero: ");
    scanf("%u", &numero);

    decompoe(numero);

    return EXIT_SUCCESS;
}

bool eh_primo(unsigned x) {
    unsigned u;
    for (u=2; u<x; ++u) {
        if (x % u == 0) {
            return false;
        }
    }
    return true;
}

void decompoe(unsigned n) {
    bool imprimiu_anterior = false;
    unsigned i;
    for (i=2; i<=n; ++i) {
        if (eh_primo(i)) {
            unsigned expoente = 0;
            while (n % i == 0) {
                n /= i;
                ++expoente;
            }
            if (expoente > 0) {
                if (imprimiu_anterior == true) {
                    printf(" *");
                }
                printf(" %u", i);
                imprimiu_anterior = true;
                if (expoente > 1) {
                    printf("^%u", expoente);
                }
            }
        }
    }
    printf("\n");
}


