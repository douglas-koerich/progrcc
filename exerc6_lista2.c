#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int angulo;
    printf("Digite o angulo: ");
    scanf("%d", &angulo);

    int quadrante, reduzido, voltas;
    bool horario;

    reduzido = angulo % 360;
    voltas = angulo / 360; // quantidades "inteiras" de 360 graus
    if (voltas < 0) {
        voltas = -voltas; // para mostrar o numero /absoluto/ de voltas
    }
    horario = angulo < 0; // salva /true/ ou /false/ dependendo da comparacao

    if (reduzido < 0) { // compara com limites de quadrantes negativos
        if (reduzido >= -90) {
            quadrante = 4;
        } else {
            if (reduzido >= -180) {
                quadrante = 3;
            } else {
                if (reduzido >= -270) {
                    quadrante = 2;
                } else {
                    quadrante = 1;
                }
            }
        }
    } else { // compara com limites de quadrantes positivos
        // if (reduzido >= 0 && reduzido < 90) { // comparacao com 0 desnecessaria
        if (reduzido < 90) {
            quadrante = 1;
        } else {
            if (reduzido < 180) {
                quadrante = 2;
            } else {
                if (reduzido < 270) {
                    quadrante = 3;
                } else {
                    quadrante = 4;
                }
            }
        }
    }
    printf("O angulo reduzido eh %d graus, no %do. quadrante, apos %d voltas no sentido ",
           reduzido, quadrante, voltas);
    if (horario) {
        printf("horario\n");
    } else {
        printf("anti-horario\n");
    }

    return EXIT_SUCCESS;
}

