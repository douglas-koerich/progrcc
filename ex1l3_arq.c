#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FILE* tabF2C = fopen("f2c.txt", "w");
    if (tabF2C == 0) {
        perror("Nao foi possivel criar a tabela Fahrenheit --> Celsius");
        return EXIT_FAILURE;
    }
    float celsius, fahrenheit;

    if (fputs("Fahrenheit,Celsius\n", tabF2C) == EOF) { // fputs nao poe \n
        perror("Nao foi possivel iniciar o arquivo da tabela");
        fclose(tabF2C);
        return EXIT_FAILURE;
    }
    for (fahrenheit = -150.0; fahrenheit <= +150.0; fahrenheit += 1.0) {
        celsius = 5 * (fahrenheit - 32) / 9;
        fprintf(tabF2C, "%.0f,%.2f\n", fahrenheit, celsius);
    }

    fclose(tabF2C);

    FILE* tabC2F = fopen("c2f.txt", "w");
    if (tabC2F == 0) {
        perror("Nao foi possivel criar a tabela Celsius --> Fahrenheit");
        return EXIT_FAILURE;
    }
    if (fputs("Celsius,Fahrenheit\n", tabC2F) == EOF) {
        perror("Nao foi possivel iniciar o arquivo da segunda tabela");
        fclose(tabC2F);
        return EXIT_FAILURE;
    }
    for (celsius = -150.0; celsius <= +150.0; celsius += 1.0) {
        fahrenheit = celsius * 9 / 5 + 32;
        fprintf(tabC2F, "%.0f,%.2f\n", celsius, fahrenheit);
    }
    fclose(tabC2F);

    return EXIT_SUCCESS;
}

