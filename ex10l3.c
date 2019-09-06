#include <stdlib.h>
#include <stdio.h>

int main() {
    const double a = 0.0, b = 1.0; // const impede a mudanca da variavel
    unsigned n;

    printf("Quantas divisoes entre 0 e 1 serao feitas? ");
    scanf("%u", &n);

    double delta_x = (b - a) / n;
    double x_i, x_i_menos_1, y_i, y_i_menos_1, A, A_total = 0.0;

    for (x_i_menos_1 = a, x_i = a + delta_x; x_i <= b;) { // sem incrementos
        // Calculo das bases (y's)
        y_i_menos_1 = 1 / (1 + x_i_menos_1 * x_i_menos_1); // aplicacao de f(x)
        y_i = 1 / (1 + x_i * x_i);

        // Calculo da area e acumulo no total
        A = (y_i + y_i_menos_1) / 2 * delta_x; // area do trapezio "da vez"
        A_total += A; // soma essa area no total das areas

        // Atualizacao dos x's para o proximo passo do laco
        x_i_menos_1 = x_i;
        x_i = x_i_menos_1 + delta_x;
    }

    // O valor de pi eh a multiplicacao da "integral" (aproximada pelo laco)
    // por 4
    double S = 4 * A_total;

    printf("O valor calculado de PI eh %.12lf\n", S);

    return EXIT_SUCCESS;
}

