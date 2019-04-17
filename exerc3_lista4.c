#include <stdlib.h>
#include <stdio.h>

// Prototipo da funcao
float soma(unsigned);

int main(void) {
    printf("Digite o numero de termos (N): ");
    unsigned var;
    scanf("%u", &var);

    float y;
    y = soma(var);

    printf("O somatorio da serie eh %f.\n", y);

    return EXIT_SUCCESS;
}

float soma(unsigned N) {
    unsigned n; // que varia de 1 ateh N
    float S; // que vai ser calculada e retornada

    // Laco de calculo de S eh...
    for (n = 1, S = 0.0; n <= N; ++n) {
        // float termo = (n * n + 1) / (n + 3); (DIVISAO INTEIRA!)
        // float termo = (n * n + 1) / ((float) n + 3); (resolvendo por cast)
        float termo = (n * n + 1.0) / (n + 3); // (resolvendo por cte. float)
        S += termo;
    }
    return S;
}

