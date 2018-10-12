#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float media_aritmetica(int [*], size_t);
float desvio_medio(int [*], size_t);
float desvio_padrao(int [*], size_t);

int main(void) {
    printf("Qual o tamanho do vetor X? ");
    int n;
    scanf("%d", &n);

    int X[n], i;
    for (i=0; i<n; ++i) {
        printf("X[%d]? ", i);
        scanf("%d", &X[i]);
    }

    printf("O desvio medio do vetor eh %f.\n", desvio_medio(X, n));
    printf("O desvio padrao do vetor eh %f.\n", desvio_padrao(X, n));

    return EXIT_SUCCESS;
}

float desvio_medio(int x[], size_t n) {
    float x_barra = media_aritmetica(x, n);
    int i;
    float soma = 0.0;
    for (i=0; i<n; ++i) {
        soma += fabsf(x[i] - x_barra); // valor absoluto do float
    }
    float DM = soma / n;
    return DM;
}

float media_aritmetica(int x[], size_t n) {
    float soma = 0.0;
    int i;
    for (i=0; i<n; ++i) {
        soma += x[i];
    }
    return soma / n;
}

float desvio_padrao(int x[], size_t n) {
    float x_barra = media_aritmetica(x, n);
    int i;
    float soma = 0.0;
    for (i=0; i<n; ++i) {
        soma += pow(fabsf(x[i] - x_barra), 2);
    }
    float sigma = sqrt(soma / (n-1));
    return sigma;
}

