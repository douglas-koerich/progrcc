#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    printf("Digite um numero para teste: ");
    scanf("%d", &n);
    bool teste = n % 2 == 0; // teste recebe 'true' ou 'false'
                             // de acordo com a comparacao
    if (!teste) {
        printf("O numero eh impar\n");
    } else {
        printf("O numero eh par\n");
    }
/*
    if (n % 2) { // se o resultado for 1, C entende como 'verdadeiro',
                 // ao passo que se for 0, serah interpretado como 'falso'
        printf("O numero eh impar\n");
    } else {
        printf("O numero eh par\n");
    }
*/
/*
    int resto = n % 2; // resto terah 0 ou 1
    if (resto = 0) { // esse erro (falta de um '=') faz imprimir sempre 'impar'!
        printf("O numero eh par\n");
    } else {
        printf("O numero eh impar\n");
    }
*/
    return EXIT_SUCCESS;
}

