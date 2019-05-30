#include <stdio.h>
#include <ctype.h>
#include "exerc2_lista7.h"

void faz_recenseamento(habitante vetor[], size_t tamanho) {
    int i;
    for (i = 0; i < tamanho; ++i) {
        printf("Idade? "); scanf("%u", &vetor[i].idade);
        char s;
        do {
            printf("Sexo (M/F)? ");
            scanf(" %c", &s);
            s = toupper(s);
        } while (s != 'F' && s != 'M');
        vetor[i].sexo = s;
        printf("Salario? "); scanf("%f", &vetor[i].salario);
        printf("Numero de filhos? "); scanf("%u", &vetor[i].filhos);
    }
}

