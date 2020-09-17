#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%u", &n);

    unsigned divisor = 2;
    bool ainda_eh_primo = true;

    // Nao eh necessario comparar a metade superior pois a divisao seria 1.xxx
    while (divisor <= n / 2 && ainda_eh_primo == true) {
        if (n % divisor == 0) {
            printf("O numero nao eh primo!\n");

            // Nao faz sentido continuar, pode interromper o laco aqui mesmo
            ainda_eh_primo = false;
        } else {
            ++divisor;
        }
    }
    if (ainda_eh_primo) {
        printf("O numero eh primo!\n");
    }
    return EXIT_SUCCESS;
}