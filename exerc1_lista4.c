#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Prototipo da funcao de teste:
bool eh_primo(unsigned);

int main() {
    unsigned num;
    printf("Digite um numero: ");
    scanf("%u", &num);

    if (eh_primo(num)) { // usa o retorno da funcao como condicao
        printf("O numero eh primo.\n");
    } else {
        printf("O numero nao eh primo.\n");
    }
    return EXIT_SUCCESS;
}

bool eh_primo(unsigned n) {
    unsigned inter;
    for (inter = 2; inter < n; ++inter) { // valores intermediarios
        if (n % inter == 0) { // eh divisivel por um intermediario?
            return false; // sai daqui mesmo, jah indicando que NAO eh primo
        }
    }
    return true; // passei por todos os intermediarios sem um divisor
}

