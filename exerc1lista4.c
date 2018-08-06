#include <stdio.h>
#include <stdbool.h>    // para definir o tipo bool em C

bool verifica_primo(int);

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (verifica_primo(numero)) {
        printf("O numero eh primo\n");
    }
    else {
        printf("O numero NAO eh primo\n");
    }
    return 0;
}

bool verifica_primo(int numero) {
    int candidato_a_divisor = numero - 1;
    while (candidato_a_divisor > 1) {
        if (numero % candidato_a_divisor == 0) {
            return false;
        }
        --candidato_a_divisor;
    }
    return true;
}
