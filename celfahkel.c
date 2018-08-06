#include <stdlib.h>
#include <stdio.h>

void converte(float, float*, float*);

int main(void) {
    float celsius, fahrenheit, kelvin;

    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    converte(celsius, &fahrenheit, &kelvin);

    printf("A mesma temperatura em Fahrenheit: %.1f; e Kelvin: %.1f.\n",
           fahrenheit, kelvin);

    return EXIT_SUCCESS;
}

void converte(float c, float* f, float* k) {
    *k = c + 273;
    *f = 9 * c / 5 + 32;
}

