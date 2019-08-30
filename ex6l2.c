#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int angulo; // valores inteiros com sinal
    printf("Digite o valor do angulo, em graus: ");
    scanf("%d", &angulo);

    if (angulo < 0) {
        puts("Sentido horario");
    } else {
        puts("Sentido anti-horario");
    }
    int voltas = abs(angulo) / 360; // percursos inteiros de 360 graus,
                                    // desprezando o sinal (v. funcao abs)
    printf("O angulo completa %d volta(s) ao longo dos quadrantes\n", voltas);

    int reduzido = angulo % 360; // note que usa a variavel com sinal aqui
    printf("O angulo reduzido correspondente vale %d graus\n", reduzido);

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

