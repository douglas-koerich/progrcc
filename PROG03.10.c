#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Quantas divisoes (n) no intervalo entre 0 (a) e 1 (b)? ");
    scanf("%d", &n);

    double S = 0.0;  // somatorio das areas dos 'n' trapezios
    double a = 0.0, b = 1.0; // valores de 'a' e 'b' deduzidos da formula do PI
                             // no enunciado
    double delta_x = (b - a) / n;

    int trapezio;
    double y_i, y_i_menos_1, x_i, x_i_menos_1; // y_i serah calculado a partir
                                               // do x_i (o mesmo para y_i_menos_1)
    for (trapezio=1, x_i_menos_1 = a; trapezio<=n; ++trapezio, x_i_menos_1 = x_i) {
        x_i = x_i_menos_1 + delta_x;
        y_i_menos_1 = 1 / (1 + pow(x_i_menos_1, 2)); // aplicacao de f(x) para obter y
        y_i = 1 / (1 + pow(x_i, 2));

        double A = (y_i + y_i_menos_1) / 2 * delta_x; // area do trapezio DESTE passo
                                                      // (um dos 'n' trapezios)
        S += A; // acumula no total a contribuicao da area deste trapezio
    }
    double meu_pi = 4 * S;
    printf("O valor de PI calculado pela aproximacao eh %lf.\n", meu_pi);

    return EXIT_SUCCESS;
}

