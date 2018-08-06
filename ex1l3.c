#include <stdlib.h>
#include <stdio.h>

int main() {
    // Nao existe entrada de dados, apenas variaveis que vao ser usadas no
    // calculo de cada linha da tabela
    float celsius, fahrenheit;

    // Primeira tabela: conversao de Fahrenheit pra Celsius
    printf("Convertendo de Fahrenheit para Celsius:\n");
    for (fahrenheit = -150.0; fahrenheit <= 150.0; ++fahrenheit) {
        celsius = 5.0/9*(fahrenheit - 32);  // 5/9 eh uma divisao inteira=0
        printf("F = %f, C = %f\n", fahrenheit, celsius);
    }
    // Segunda tabela: conversao de Celsius pra Fahrenheit
    printf("Convertendo de Celsius para Fahrenheit:\n");
    for (celsius = -150.0; celsius <= 150.0; ++celsius) {
        fahrenheit = 9.0/5*celsius + 32;  // 9/5 eh uma divisao inteira=1
        printf("C = %f, F = %f\n", celsius, fahrenheit);
    }
    return EXIT_SUCCESS;
}

