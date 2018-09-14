#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float calcula_serie(unsigned);

int main() {
    printf("Digite o numero de termos que serao usados no calculo: ");
    unsigned termos;
    scanf("%u", &termos);

    printf("A soma dos termos eh %f\n", calcula_serie(termos));

    return EXIT_SUCCESS;
}

float calcula_serie(unsigned N) {
    float S = 0.0;
    unsigned n;
    for (n = 1; n <= N; ++n) {
        S += (pow(n, 2) + 1) / (n + 3);
    }
    return S;
}

