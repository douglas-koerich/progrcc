#include <stdlib.h>
#include <stdio.h>

int main() {
    int Y, N;

    printf("Digite o numero Y: ");
    scanf("%d", &Y);
    printf("Numero de termos da serie para calcular (N): ");
    scanf("%d", &N);

    int i;
    float P;

    for (i = 1, P = 1.0; i <= N; ++i) {
        int numerador = Y;
        int denominador = 1; /* = fatorial */

        // Calcula denominador/fatorial DENTRO do laco, pois muda para cada termo
        int j;
        // (repetir para j = 1, 2, 3, ..., i-1)
        for (j = 1; j <= (i-1); ++j) {  // ou ... ; j < i; ...
            denominador = denominador * j;  // multiplica total anterior pelo novo valor de j
        }
        // P *= Y / (i-1)!
        P *= (float) numerador / denominador;   // cast para "transformar" a divisao inteira em divisao real
    }
    printf("O resultado do produtorio eh %f.\n", P);

    return EXIT_SUCCESS;
}
