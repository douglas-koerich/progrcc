#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float x;

    do {
        printf("Digite o valor de x: ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);

    float erro;
    printf("Digite o erro (tolerancia) entre f(%.3f) e f'(%.3f): ", x, x);
    scanf("%f", &erro);

    float y, y_linha;

    y = 1 / (1 - x);
    printf("y = f(%.3f) = %f\n", x, y);

    // Para saber quantos termos sao necessarios para que erro < |f(x) - f'(x)|
    // vamos somando a f'(x) um termo de cada vez ateh que a diferenca atenda
    // ao erro definido (inequacao anterior)
    int termos = 0;
    y_linha = 0.0;
    while (erro < fabsf(y - y_linha)) {
        y_linha += pow(x, termos);
        printf("y' = f'(%.3f) = %f\n", x, y_linha); // mostrando como y_linha se aproxima de y
        ++termos;
    }
    printf("Foram necessarios %d termos para que a tolerancia fosse alcancada\n", termos);

    return EXIT_SUCCESS;
}

