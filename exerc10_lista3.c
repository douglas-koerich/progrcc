#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Quantas(os) divisoes(trapezios) serao usadas(os)? ");
    scanf("%d", &n);

    double a = 0.0, b = 1.0; // limites da integral (v. formula do Pi)

    double S = 0.0; // soma das areas dos trapezios
    double delta_x = (b - a) / n; // "altura" de cada trapezio (v. figura)

    int i;
    double x_i_menos_1 = a; // lado esquerdo do primeiro trapezio

    for (i = 1; i <= n; ++i) { // para "n" trapezios (i de 1 ateh n)...
        // calculo da base esquerda do trapezio
        double y_i_menos_1 = 1 / (1 + pow(x_i_menos_1, 2));

        // calculo da base direita do trapezio
        double x_i = x_i_menos_1 + delta_x;
        double y_i = 1 / (1 + pow(x_i, 2));

        // calculo da area
        double A = (y_i + y_i_menos_1) / 2 * delta_x;

        // soma ao total da area completa
        S += A;

        x_i_menos_1 = x_i; // o x_i deste passo serah o x_i_menos_1 do
                           // proximo passo deste laco
    }
    double pi = 4 * S; // o valor de pi eh obtido pela formula do enunciado (v.)
    printf("O valor de pi aproximado pela integral eh %.10lf.\n", pi);

    return EXIT_SUCCESS;
}

