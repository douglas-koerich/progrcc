#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

float desvio_medio(const float*, size_t);
float desvio_padrao(const float*, size_t);

float media(const float*, size_t); // funcao acessoria, usada pelas outras duas

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("%s: Numero insuficiente de parametros\n", argv[0]);
        printf("Uso: %s <numero-elems-conjunto>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);

    float vetor[n];

    /* A alocacao do vetor acima poderia ser:
    float* vetor = malloc(n * sizeof(float));
    */

    srand((unsigned) time(NULL)); // semente da geracao de numeros INTEIROS
    int i;
    puts("Vetor gerado:");
    for (i = 0; i < n; ++i) {
        int r = rand();
        vetor[i] = r / 1000 + (r % 1000 / 1000.0); // "gera" um numero real
                                                   // randomico com ateh 3 casas
        printf("%.3f ", vetor[i]);
    }
    putchar('\n'); // salto de linha apos o ultimo numero impresso

    float DM = desvio_medio(vetor, n);
    float sigma = desvio_padrao(vetor, n);

    printf("Desvio medio = %f, padrao = %f\n", DM, sigma);

    return EXIT_SUCCESS;
}

float desvio_medio(const float* conjunto, size_t tamanho) {
    int i;

    float x_barra = media(conjunto, tamanho); // media aritmetica

    float soma;
    for (i = 0, soma = 0.0; i < tamanho; ++i, ++conjunto) { // ponteiro itinerante
        float x_i = *conjunto; // ponteiro estah sempre no elemento da vez
        soma += fabsf(x_i - x_barra); // modulo (valor absoluto) da subtracao
    }
    return soma / tamanho;
}

float desvio_padrao(const float* conjunto, size_t tamanho) {
    int i;

    float x_barra = media(conjunto, tamanho);

    float soma;
    for (i = 0, soma = 0.0; i < tamanho; ++i) { // ponteiro permanece no inicio
        float x_i = *(conjunto + i); // usa aritmetica para "saltar" pro elemento
        soma = pow(x_i - x_barra, 2);
    }
    return sqrt(soma / (tamanho-1));
}

float media(const float* conjunto, size_t tamanho) {
    int i;
    float soma;
    for (i = 0, soma = 0.0; i < tamanho; ++i) {
        float x_i = conjunto[i]; // indexando um ponteiro...
        soma += x_i;
    }
    return soma / tamanho;
}

