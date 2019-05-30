#include "exerc2_lista7.h"

unsigned menor_idade(const habitante vetor[], size_t tamanho) {
    int i;
    unsigned idade_m;
    for (i = 0; i < tamanho; ++i) {
        if (i == 0) {
            idade_m = vetor[i].idade;
        } else if (idade_m > vetor[i].idade) {
            idade_m = vetor[i].idade;
        }
    }
    return idade_m;
}

unsigned maior_idade(const habitante vetor[], size_t tamanho) {
    int i;
    unsigned idade_M;
    for (i = 0; i < tamanho; ++i) {
        if (i == 0 || idade_M < vetor[i].idade) {
            idade_M = vetor[i].idade;
        }
    }
    return idade_M;
}
