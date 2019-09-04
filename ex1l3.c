#include <stdlib.h>
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    puts("Fahrenheit --> Celsius");
    for (fahrenheit = -150.0; fahrenheit <= +150.0; fahrenheit += 1.0) {
        celsius = 5 * (fahrenheit - 32) / 9; // nao faca 5/9*(fahrenheit-32)!
        printf("F = %.0f <==> C = %.2f\n", fahrenheit, celsius);
    }

    puts("\nCelsius --> Fahrenheit");
    for (celsius = -150.0; celsius <= +150.0; celsius += 1.0) {
        fahrenheit = celsius * 9 / 5 + 32;
        printf("C = %.0f <==> F = %.2f\n", celsius, fahrenheit);
    }
    return EXIT_SUCCESS;
}

