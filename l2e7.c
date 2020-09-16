#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float A, B, C;

    printf("Digite o coeficiente do termo x^2 (A): ");
    scanf("%f", &A);
    printf("Digite o coeficiente do termo x (B): ");
    scanf("%f", &B);
    printf("Digite o valor do termo isolado (C): ");
    scanf("%f", &C);

    float delta = B * B - 4 * A * C;

    if (delta < 0.0) {
        printf("A equacao nao tem raizes reais\n");
    } else {
        if (A == 0) {
            float x = -C / B;
            printf("A equacao tem uma raiz unica igual a %f\n", x);
        } else {
            float x1, x2;
            x1 = (-B + sqrt(delta)) / (2 * A);
            x2 = (-B - sqrt(delta)) / (2 * A);
            printf("A equacao tem raizes %f e %f\n", x1, x2);
        }
    }
    return EXIT_SUCCESS;
}