#include <stdbool.h> // para uso de bool
#include <stdlib.h>
#include <stdio.h>

int main() {
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Nao aceito numeros negativos!\n");
        return EXIT_FAILURE;
    }

    /* se resto(numero, 2) = 0 entao
     *     escreva "Eh par"
     * senao
     *     escreva "Eh impar"
     * fim-se
     */
    int resto = numero % 2;
    if (resto == 0) {
        printf("Eh par\n");
    } else {
        printf("Eh impar\n");
    }

    if (numero < 10) {
        printf("Primeira dezena\n");
    } else { // todas as outras dezenas seguintes...
        if (numero < 20) {
            printf("Segunda dezena\n");
        } else { // todas as outras seguintes...
            if (numero < 30) {
                printf("Terceira dezena\n");
            } else { // cansei...
                printf("Uma dezena bem grande...\n");
            }
        }
    }

    return EXIT_SUCCESS;
}

