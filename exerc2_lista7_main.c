#include <stdlib.h>
#include <stdio.h>
#include "exerc2_lista7.h"

int main(void) {
    size_t num_habitantes;
    printf("Digite o tamanho da populacao recenseada: ");
    scanf("%zd", &num_habitantes);

    habitante populacao[num_habitantes];

    faz_recenseamento(populacao, num_habitantes);

    float media = media_salario(populacao, num_habitantes);
    unsigned idade_m = menor_idade(populacao, num_habitantes);
    unsigned idade_M = maior_idade(populacao, num_habitantes);
    size_t num = num_mulheres_3filhos_ate900reais(populacao, num_habitantes);

    printf("Estatisticas:\nMedia de salario = R$ %.2f\n", media);
    printf("Idades extremas = %u e %u\n", idade_m, idade_M);
    printf("Mulheres com 3 filhos e salario <= 900 = %zd\n", num);

    return EXIT_SUCCESS;
}

