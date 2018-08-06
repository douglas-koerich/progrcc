#include <stdlib.h>
#include <stdio.h>

float calcula_somatorio(unsigned);

int main(void) {
    printf("Digite o numero de termos a serem calculados (N): ");
    unsigned N;
    scanf("%u", &N);
    float S = calcula_somatorio(N);
    printf("O resultado do somatorio calculado eh %f.\n", S);
    return EXIT_SUCCESS;
}

float calcula_somatorio(unsigned N) {
    unsigned n; // da formula, eh a variavel de controle do laco
    float soma = 0.0;
    for (n = 1; n <= N; ++n) {
        soma += (n*n+1.0)/(n+3);
    }
    return soma;
}

