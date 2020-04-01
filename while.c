#include <stdlib.h>
#include <stdio.h>

int main() {
    int maximo = 100, acumulador;

    printf("Digite um valor inicial para o acumulador: ");
    scanf("%d", &acumulador);

    // Pede numeros a serem somados no acumulador enquanto esse valor total
    // nao ultrapassa o maximo
    while (acumulador < maximo) {
        printf("Digite um numero pra somar ao acumulador: ");
        int numero; // leia sobre "variaveis locais" na bibliografia
        scanf("%d", &numero);

        acumulador += numero; // acumulador = acumulador + numero; (diferente de acum = num + acum)
    }

    printf("O acumulador ultrapassou o maximo valendo %d\n", acumulador);

    return EXIT_SUCCESS;
}

