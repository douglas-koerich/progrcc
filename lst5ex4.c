#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

float media(float [], size_t);
float desvio_medio(float [], size_t);
float desvio_padrao(float [], size_t);

#define NUM_ELEMENTOS 10

int main(void) {
    /*
    float exemplo[NUM_ELEMENTOS] = {
        1, 2, 4, 7, 2.5, -3.1, 0.03, 14.2, 6.2, -2.77 };

    printf("O desvio medio do vetor eh %.1f\n",
           desvio_medio(exemplo, NUM_ELEMENTOS));

    float dpadrao = desvio_padrao(exemplo, NUM_ELEMENTOS);
    */

    size_t tamanho;
    printf("Digite o tamanho do conjunto de valores 'x': ");
    scanf("%zu", &tamanho);

    float exemplo[tamanho]; // usuario definiu o tamanho do vetor
                            // em tempo de execucao
    // Preenche o vetor com numeros aleatorios de 0 a 9.9, com
    // uma casa apos a virgula
    srand(time(0)); // inicializa a semente aleatoria com a leitura
                    // do valor de ticks do relogio do PC
    int indice;
    printf("Vetor gerado aleatoriamente:\n");
    for (indice = 0; indice < tamanho; ++indice) {
        exemplo[indice] = rand() % 100 / 10.0;
        printf("%.1f ", exemplo[indice]);
    }
    printf("\n"); // salta a linha para a proxima impressao

    printf("O desvio medio do vetor eh %.1f\n",
           desvio_medio(exemplo, tamanho));

    float dpadrao = desvio_padrao(exemplo, tamanho);
    printf("O desvio padrao do vetor eh %.1f\n", dpadrao);

    return EXIT_SUCCESS;
}

float media(float x[], size_t n) {
    float soma = 0.0;
    int i;
    for (i = 0; i < n; ++i) {
        soma += x[i];
    }
    return soma / n;
}

float desvio_medio(float x[], size_t n) {
    float x_barra = media(x, n); // passa o vetor recebido
    float soma = 0.0;
    int i;
    for (i = 0; i < n; ++i) {
        soma += fabsf(x[i] - x_barra);
    }
    return soma / n;
}

float desvio_padrao(float x[], size_t n) {
    float x_barra = media(x, n);
    float soma = 0.0;
    int i;
    for (i = 0; i < n; ++i) {
        soma += pow(x[i] - x_barra, 2);
    }
    return sqrt(soma / (n-1));
}

