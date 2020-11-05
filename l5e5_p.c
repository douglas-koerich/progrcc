#include <stdlib.h>
#include <stdio.h>
#include <time.h>

size_t remove_numero(int*, size_t, int);

int main(void) {
    size_t tamanho;
    printf("Digite o tamanho do vetor de exemplo: ");
    scanf("%zu", &tamanho);

    int vetor[tamanho], *pv = vetor; // inicia o ponteiro no endereco do primeiro elemento do vetor

    // Gera um conteudo aleatorio para o vetor
    srand((unsigned) time(0));
    int indice;
    for (indice = 0; indice < tamanho; ++indice) {
        *(pv + indice) = rand() % 10;
        printf("%d ", *(pv + indice));
    }

    int numero;
    printf("\n\nDigite o numero que deseja remover desse conjunto: ");
    scanf("%d", &numero);

    tamanho = remove_numero(pv, tamanho, numero);

    printf("Apos a remocao (ou nao) do numero:\n");
    for (indice = 0; indice < tamanho; ++indice, ++pv) {
        printf("%d ", *pv);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

size_t remove_numero(int* vet, size_t tam, int num) {
    int i = 0;
    while (i < tam) {
        if (vet[i] != num) {
            ++i;
        } else {
            int j;
            for (j = i+1; j < tam; ++j) {
                vet[j-1] = vet[j];
            }
            --tam;
        }
    }
    return tam;
}