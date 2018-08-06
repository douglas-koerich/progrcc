#include <stdlib.h>
#include <stdio.h>

#define NUM 10

int maiorValor(int [*], size_t);    // retorna um valor
int indiceMenor(int [*], size_t);   // retorna um indice

int main(void) {
    // Inicializacao de um vetor com posicoes salteadas
    int vetor[NUM] = { [1] = 45, [6] = 70, [8] = -1 };

    // Percurso no vetor inicializado
    int i;
    for (i=0; i<NUM; ++i) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
    }

    int maior = maiorValor(vetor, NUM);  // soh o nome da variavel-vetor
    printf("O maior valor dentro do vetor eh %d.\n", maior);

    i = indiceMenor(vetor, NUM);
    printf("O menor valor do vetor estah na posicao (indice) %d.\n", i);

    return EXIT_SUCCESS;
}

int maiorValor(int vet[], size_t tam) {
    // Algoritmo para descobrir o maior valor de elemento do vetor
    int i, maior_valor = vet[0];
    for (i=0; i<tam; ++i) {
        if (vet[i] > maior_valor) {
            maior_valor = vet[i];
        }
    }
    return maior_valor;
}

int indiceMenor(int vet[], size_t tam) {
    // Algoritmo para descobrir o indice do menor elemento do vetor
    int i, indice_menor = 0, menor_valor = vet[0];
    for (i=0; i<tam; ++i) {
        if (vet[i] < menor_valor) {
            menor_valor = vet[i];
            indice_menor = i;
        }
    }
    return indice_menor;
}
