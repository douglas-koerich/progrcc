#include <stdlib.h>
#include <stdio.h>

int main() {
    float Y, produto;
    int N, i;

    printf("Digite o valor de Y: ");
    scanf("%f", &Y);
    printf("Quantos termos para a serie (N)? ");
    scanf("%d", &N);

    for (i = produto = 1; i <= N; ++i) { // repete pelo numero de termos definido pelo usuario (N)
        // Eh necessario calcular o fatorial de (i-1) para aplicar neste passo do laco
        int x, fatorial = 1;
        for (x = i - 1; x >= 1; --x) { // x = i-1, i-2, i-3, ..., 4, 3, 2, 1
            fatorial *= x;
        }
        produto *= Y / fatorial;
    }

    printf("O produtorio eh igual a %f\n", produto);

    return EXIT_SUCCESS;
}