#include <stdlib.h>
#include <stdio.h>

int main() {
    float Y;
    unsigned N, i;

    printf("Digite o valor de Y: "); scanf("%f", &Y);
    printf("Numero de termos da serie (N): "); scanf("%u", &N);

    float P = 1.0; // elemento neutro da multiplicacao

    for (i = 1; i <= N; ++i) { // para cada termo da serie...
        unsigned j, denominador = 1; // denominador eh o fatorial
        for (j = 1; j < i; ++j) { // fatorial de 1 a i-1
            denominador *= j; // denominador = denominador * j;
        }
        float termo = Y / denominador;
        P *= termo;
    }

    printf("O produto dos termos eh %f\n", P);

    return EXIT_SUCCESS;
}
