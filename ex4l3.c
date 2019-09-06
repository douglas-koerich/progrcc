#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    if (n < 0) {
        n = -n; // usar o numero sem sinal
    }

    int i;
    bool primo;
    // for (i=2, primo=true; i<n && primo; ++i) {
    for (i=2, primo=true; i<=n/2 && primo; ++i) {
        if (n % i == 0) {
            primo = false;
            /* Ao inves do teste do primo no for...
            break; // nao eh necessario continuar o laco
            */
        }
    }
    if (primo) {
        puts("O numero eh primo!");
    } else {
        puts("O numero NAO eh primo!");
    }

    return EXIT_SUCCESS;
}

