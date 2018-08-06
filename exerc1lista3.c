#include <stdlib.h>
#include <stdio.h>

int main() {
    int minimo = -150, maximo = +150, grau;

    // Primeira tabela: de Fahrenheit para Celsius
    for (grau = minimo; grau <= maximo; ++grau) {
        float celsius;
        celsius = 5.0/9*(grau - 32); // usa 5.0 pra fazer a divisao ser REAL
        printf("F = %d --> C = %.1f\n", grau, celsius);
    }

    // Segunda tabela: de Celsius para Fahrenheit (segue o mesmo algoritmo)
    grau = minimo;
    for (; grau <= maximo; ++grau) { // as partes do for podem ser omitidas
        float fahrenheit;
        fahrenheit = 9/5.0*grau + 32;
        printf("C = %d --> F = %.1f\n", grau, fahrenheit);
    }
    return EXIT_SUCCESS;
}
