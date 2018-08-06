#include <stdlib.h>
#include <stdio.h>

int main() {
    float r1, r2, theta1, theta2;

    // Forma segura de entrada: uma variavel para cada scanf()
    printf("Digite o coeficiente r de Z1: ");
    scanf("%f", &r1);
    printf("Digite o parametro Theta de Z1: ");
    scanf("%f", &theta1);

    // Forma mais pratica, mas dependente da competencia do
    // usuario do programa
    printf("Digite os parametros de Z2 na forma r,Theta: ");
    scanf("%f,%f", &r2, &theta2);

    float mul_r, div_r;
    float soma_theta, sub_theta;

    mul_r = r1 * r2;
    div_r = r1 / r2;

    soma_theta = theta1 + theta2;
    sub_theta = theta1 - theta2;

    printf("Z1 = %.3f.e^(i%.3f)\n", r1, theta1);
    printf("Z2 = %.3f.e^(i%.3f)\n", r2, theta2);
    printf("Z1*Z2 = %.3f.e^(i%.3f)\n", mul_r, soma_theta);
    printf("Z1/Z2 = %.3f.e^(i%.3f)\n", div_r, sub_theta);

    return EXIT_SUCCESS;
}
