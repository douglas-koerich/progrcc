#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float media(float [*], int);
float desvio_medio(float [*], int);
float desvio_padrao(float [*], int);

int main(void) {
    printf("Qual o tamanho do vetor a ser usado? ");
    int n;
    scanf("%d", &n);

    float x[n]; // o vetor de elementos "x"

    int i;
    for (i = 0; i < n; ++i) {
        printf("Digite o valor de x%d: ", i+1);
        scanf("%f", &x[i]);
    }
    printf("O desvio medio do vetor eh %f.\n", desvio_medio(x, n));
    printf("O desvio padrao do vetor eh %f.\n", desvio_padrao(x, n));

    return EXIT_SUCCESS;
}

float media(float x[], int n) {
    float soma = 0.0;
    int i = 1;  // vou seguir a formula, fazendo somatorio para i de 1 a n...
    while (i <= n) {
        soma += x[i-1]; // ...mas nao posso esquecer que o vetor comeca em 0
        ++i;
    }
    return soma / n;
}

float desvio_medio(float x[], int n) {
    float x_barra = media(x, n);
    float soma = 0.0;
    int i;
    for (i = 1; i <= n; ++i) { // troquei o while por for agora... :-)
        soma += fabsf(x[i-1] - x_barra);
    }
    return soma / n;
}

float desvio_padrao(float x[], int n) {
    float x_barra = media(x, n);
    float soma = 0.0;
    int i;
    for (i = 0; i < n; ++i) { // comecar em 0 e ir ateh n-1 sao os mesmos n passos
        soma += pow(fabsf(x[i] - x_barra), 2);
    }
    return sqrt(soma / (n-1));
}

