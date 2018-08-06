#include <stdlib.h>
#include <stdio.h>

int main() {
    int n; // numero de trapezios/divisoes sob a curva da funcao
    int a = 0, b = 1;

    printf("Digite o numero de divisoes a considerar: ");
    scanf("%d", &n);

    double delta_x = ((double)b - a)/n;   // cast para forcar divisao REAL
    double S = 0.0; // S eh o somatorio das areas dos trapezios

    double x;      // inicializa x em x0 = a
    double y;      // correspondente a x na formula 1/(1+x²)
    double x_prox; // o x seguinte (para calcular a outra base)
    double y_prox; // obtido de x_prox pela mesma formula

    for (x = a; x < b; x += delta_x) {
        y = 1 / (1 + x * x);    // calcula a primeira base (da esquerda)
        x_prox = x + delta_x;
        y_prox = 1 / (1 + x_prox * x_prox); // calcula a segunda base (direita)
        double A = (y + y_prox) * delta_x / 2; // calcula a area deste trapezio
        S += A; // soma a area do trapezio ao total acumulado
    }

    double pi = 4 * S;
    printf("PI = %lf\n", pi);

    return EXIT_SUCCESS;
}
