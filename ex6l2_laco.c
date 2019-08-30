#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float angulo;
    printf("Digite o valor do angulo, em graus: ");
    scanf("%f", &angulo);

    int voltas = 0;
    if (angulo < 0) {
        puts("Sentido horario");
        // enquanto angulo <= -360.0 faca
        //     angulo <- angulo + 360 ; desconta uma volta negativa
        //     voltas <- voltas + 1
        // fim-enquanto
        while (angulo <= -360.0) {
            angulo += 360;
            ++voltas;
        }
    } else {
        puts("Sentido anti-horario");
        // enquanto angulo >= +360.0 faca
        //     angulo <- angulo - 360 ; desconta uma volta positiva
        //     voltas <- voltas + 1
        // fim-enquanto
        while (angulo >= 360.0) {
            angulo -= 360;
            ++voltas;
        }
    }
    printf("O angulo completa %d volta(s) ao longo dos quadrantes\n", voltas);

    float reduzido = angulo; // o que sobrou dos descontos feitos no laco acima
    printf("O angulo reduzido correspondente vale %f graus\n", reduzido);

    printf("Localizado no ");
    if ((reduzido >= 0 && reduzido < 90) || (reduzido >= -360 && reduzido < -270)) {
        puts("Primeiro quadrante");
    } else {
        if ((reduzido >= 90 && reduzido < 180) ||
            (reduzido >= -270 && reduzido < -180)) {
            puts("Segundo quadrante");
        } else {
            if ((reduzido >= 180 && reduzido < 270) ||
                (reduzido >= -180 && reduzido < -90)) {
                puts("Terceiro quadrante");
            } else {
                puts("Quarto quadrante");
            }
        }
    }
    return EXIT_SUCCESS;
}

