#include <stdlib.h>
#include <stdio.h>
#include "fatorial.h"

int main() {
    int Y, N;

    printf("Digite o valor de Y da expressao: ");
    scanf("%d", &Y);
    printf("Digite o numero de termos da serie a ser calculada: ");
    scanf("%d", &N);

    int i;
    float P = 1.0; // valor inicial do produtorio

    for (i = 1; i <= N; ++i) {
        float fatorial = fact(i-1); // variavel local ao INTERIOR do laco for
        P *= Y / fatorial; // P *= Y / fact(i-1);
    }

    printf("O produto dos termos segundo a serie eh %f\n", P);

    return EXIT_SUCCESS;
}
