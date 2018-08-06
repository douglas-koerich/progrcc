#include <stdlib.h>
#include <stdio.h>

int main() {
    int angulo; // positivos e negativos
    printf("Digite o valor do angulo: ");
    scanf("%d", &angulo);

    // Operador ternario ?:
    int modulo = angulo < 0? -angulo: angulo;

    if (angulo < 0) {   // angulo negativo?
        // modulo = -angulo;
        printf("Sentido horario\n");
    }
    else {
        // modulo = angulo;
        printf("Sentido anti-horario\n");
    }
    int voltas = modulo / 360;  // quociente inteiro eh o numero de voltas
    printf("O numero de voltas completas do angulo eh %d\n", voltas);

    int reduzido = angulo % 360;    // angulo reduzido negativo ou positivo
    printf("O angulo reduzido vale %d\n", reduzido);

    if (reduzido >= 0) {
        if (reduzido < 90) {
            printf("Primeiro quadrante\n");
        }
        else /* maior ou igual a 90 */ if (reduzido < 180) {
            printf("Segundo quadrante\n");
        }
        else if (reduzido < 270) {
            printf("Terceiro quadrante\n");
        }
        else {  // ateh 360, exclusive, porque reduzido eh o resto da divisao por 360
            printf("Quarto quadrante");
        }
    }
    else {
        if (reduzido < -270) {  // de -360 (inclusive) a -270 (exclusive)
            printf("Primeiro quadrante\n");
        }
        else if (reduzido < -180) {
            printf("Segundo quadrante\n");
        }
        else if (reduzido < -90) {
            printf("Terceiro quadrante\n");
        }
        else {
            printf("Quarto quadrante");
        }
    }
    return EXIT_SUCCESS;
}
