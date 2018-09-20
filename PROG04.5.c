#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool eh_palindromo(int);

int main(void) {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (eh_palindromo(numero)) {
        printf("O numero eh palindromo!\n");
    } else {
        printf("O numero NAO eh palindromo.\n");
    }
    return EXIT_SUCCESS;
}

bool eh_palindromo(int N) {
    int invertido = 0, n = N;
    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
    }
    return invertido == N;
}

