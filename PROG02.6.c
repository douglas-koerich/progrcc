#include <stdlib.h>
#include <stdio.h>

int main() {
    int angulo;
    printf("Digite o angulo original: ");
    scanf("%d", &angulo);

    if (angulo < 0) {
        printf("O sentido do angulo eh HORARIO\n");
    } else {
        printf("O sentido do angulo eh ANTI-HORARIO\n");
    }
    int voltas = angulo / 360; // divisao INTEIRA:
                               // se angulo for 60, voltas = 0
                               // se angulo for 400, voltas = 1
    if (voltas < 0) { // divisao inteira NAO elimina o sinal
        voltas = -voltas; // conta o numero de voltas em valor absoluto
    }
    /* Alternativa:
     * unsigned voltas = abs(angulo/360);
     */
    printf("O numero de voltas (completas) do angulo eh %d\n", voltas);

    int reduzido = angulo % 360; // o que sobra das voltas completas
                                 // de 360 graus
                                 // note que o sinal do angulo original se mantem
    printf("O angulo reduzido eh %d\n", reduzido);

    if ((reduzido >= 0 && reduzido < 90) || (reduzido >= -360 && reduzido < -270)) {
        printf("O angulo esta no PRIMEIRO quadrante\n");
    } else if ((reduzido >= 90 && reduzido < 180) || (reduzido >= -270 && reduzido < -180)) {
        printf("O angulo esta no SEGUNDO quadrante\n");
    } else if ((reduzido >= 180 && reduzido < 270) || (reduzido >= -180 && reduzido < -90)) {
        printf("O angulo esta no TERCEIRO quadrante\n");
    } else {
        printf("O angulo esta no QUARTO quadrante\n");
    }

    return EXIT_SUCCESS;
}

