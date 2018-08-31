#include <stdlib.h>
#include <stdio.h>

/* Este estupido programa lista todas as temperaturas em
 * graus Celsius que entre 0 Kelvin e um valor Kelvin digitado
 * pelo usuario... */

int main() {
    int kelvin, celsius;

    printf("Digite uma temperatura em kelvin: ");
    scanf("%d", &kelvin);

    // Imprime uma temperatura Celsius por linha...
    while (kelvin >= 0) {
        celsius = kelvin - 273;
        printf("K = %d, C = %d\n", kelvin, celsius);
        --kelvin;
    }
    /* Versao alternativa
    while (kelvin >= 0)
        printf("K = %d, C = %d\n", kelvin, kelvin - 273), --kelvin;
    */

    return EXIT_SUCCESS;
}
