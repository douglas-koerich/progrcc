#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned numero;

    printf("Digite um numero: ");
    scanf("%u", &numero);

    unsigned i;
    double produto;
    for (produto = 1.0, i = numero; i >= 1; --i) {
        produto *= i;
    }

    printf("O fatorial de %u eh %e.\n", numero, produto);

    return EXIT_SUCCESS;
}

