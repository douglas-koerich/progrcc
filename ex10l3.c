#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int n;  // numero de divisoes (trapezios) usados pra calcular o valor de Pi
    printf("Digite o valor de n para calculo de PI: ");
    scanf("%d", &n);

    double a = 0.0, b = 1.0; // da formula
    double delta_x = (b-a)/n;

    double x = a;    // a eh o primeiro valor de x (x0)
    double S = 0;    // soma dos trapezios (integral aproximada) inicializada

    int i;
    // Para cada trapezio...
    for (i=1; i<=n; ++i) {
        // Cada y eh calculado aplicando o valor correspondente de x na formula 1/(1+x^2)
        double y_menor = 1 / (1 + x*x);
        double y_maior = 1 / (1 + pow(x+delta_x, 2));
        double A = (y_menor + y_maior) / 2 * delta_x;
        S += A;
        x += delta_x;   // pula para proximo trapezio
    }
    // Ao final do laco, temos a soma das areas que eh a integral aproximada
    double PI = 4 * S;
    printf("O valor aproximado de PI para n = %d eh %lf\n", n, PI);

    return EXIT_SUCCESS;
}
