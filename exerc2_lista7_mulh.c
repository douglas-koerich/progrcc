#include "exerc2_lista7.h"

size_t num_mulheres_3filhos_ate900reais(const habitante vetor[], size_t tamanho) {
    size_t contador = 0;
    int i;
    for (i = 0; i < tamanho; ++i) {
        if (vetor[i].sexo == 'F' && vetor[i].filhos == 3 && vetor[i].salario <= 900.0) {
            ++contador;
        }
    }
    return contador;
}

