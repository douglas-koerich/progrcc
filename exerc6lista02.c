#include <stdlib.h>
#include <stdio.h>

int main() {
    int angulo, reduzido, voltas, quadrante;

    printf("Digite o angulo (em graus): ");
    scanf("%d", &angulo);

    if (angulo < 0) {
        printf("Sentido horario.\n");
    } else {
        printf("Sentido anti-horario.\n");
    }
    voltas = angulo / 360;  // voltas inteiras de 360 graus
    printf("O numero de voltas eh %d.\n", abs(voltas)); // para o caso de ser negativo
    /* outra maneira seria fazer assim:
    if (voltas < 0) {
        voltas = -voltas;   // inverte o sinal negativo
    }
    */
    reduzido = angulo % 360;
    printf("O angulo reduzido eh %d.\n", reduzido);

    // Definicao de qual eh o quadrante depende do angulo ser positivo ou negativo
    if (reduzido < 0) {
        // Testes tem que considerar a divisao dos quadrantes pelos angulos negativos
        if (reduzido >= -90 && reduzido < 0) {  // if (reduzido >= -90) {
            printf("Quarto quadrante.\n");
        } else {
            if (reduzido >= -180 && reduzido < -90) {   // if (reduzido >= -180) {
                printf("Terceiro quadrante.\n");
            } else {
                if (reduzido >= -270 && reduzido < -180) {  // if (reduzido >= -270) {
                    printf("Segundo quadrante.\n");
                } else {
                    printf("Primeiro quadrante.\n");
                }
            }
        }
    } else {
        // Agora os testes mudam as faixas de controle, com angulos positivos
        if (reduzido >= 0 && reduzido < 90) {
            printf("Primeiro quadrante.\n");
        } else {
            if (reduzido > 90 && reduzido <= 180) {
                printf("Segundo quadrante.\n");
            } else {
                if (reduzido > 180 && reduzido <= 270) {
                    printf("Terceiro quadrante.\n");
                } else {
                    printf("Quarto quadrante.\n");
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
