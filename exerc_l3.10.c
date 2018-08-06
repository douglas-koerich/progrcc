#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
y = f(x) = __1__
           1+x^2
*/

int main() {
    unsigned n;     // numero de divisoes do intervalo (b-a)
    const double a = 0.0, b = 1.0;    // limites do intervalo (v. formula)

    printf("Digite o numero de divisoes para o calculo da integral: ");
    scanf("%u", &n);

    double delta_x = (b - a) / n;    // na pratica, eh 1/n

    double x_i, x_i_menos_1;
    double y_i, y_i_menos_1;
    double S = 0.0; // somatorio deve ser inicializado com ZERO

    // Laco de calculo dos trapezios:
    unsigned i; // variavel de controle do laco/somatorio (v. formula)

    /*
    // Primeiro x_i_menos_1 eh a
    x_i_menos_1 = a;
    
    // Proximo (x_i) estah a distancia delta_x de x_i_menos_1
    x_i = x_i_menos_1 + delta_x;
    */

    for (i = 1, x_i_menos_1 = a; i <= n; ++i, x_i_menos_1 = x_i) {
        x_i = x_i_menos_1 + delta_x;

        double A_i;  // area do trapezio da vez
        double y_i = 1 / (1 + pow(x_i, 2));  // aplicacao direta da funcao
        double y_i_menos_1 = 1 / (1 + pow(x_i_menos_1, 2));

        // Calculo da area (formula do trapezio)
        A_i = (y_i_menos_1 + y_i) * delta_x / 2;

        // Acumula a area no somatorio
        S += A_i;

        /*
        x_i_menos_1 = x_i;  // para o proximo passo/trapezio
        */
    }

    // Finalizando, o calculo de PI eh feito com a multiplicacao simples
    double pi = 4 * S;
    printf("O valor (aproximado) de PI eh %.12lf.\n", pi);

    return EXIT_SUCCESS;
}

