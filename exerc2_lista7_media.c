#include "exerc2_lista7.h"

float media_salario(const habitante vetor[], size_t tamanho) {
    int i;
    float soma = 0.0;
    for (i = 0; i < tamanho; ++i) {
        soma += vetor[i].salario;
    }
    return soma / tamanho;
}
