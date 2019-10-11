#include <stdlib.h>
#include <stdio.h>

size_t retira_valor(int [*], size_t, int); // ultimo parametro eh o valor
                                           // devolve o tamanho que restou!

#define TAMANHO 10

int main(void) {
    int vetor[TAMANHO], valor, i;
    for (i = 0; i < TAMANHO; ++i) {
        printf("Digite um valor para a posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    printf("Qual numero deseja remover do vetor? ");
    scanf("%d", &valor);

    size_t novo_tamanho = retira_valor(vetor, TAMANHO, valor);

    puts("Vetor apos retirada:");
    for (i = 0; i < novo_tamanho; ++i) {
        printf("%d ", vetor[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

size_t retira_valor(int vet[], size_t tam, int val) {
    size_t tam_final = tam;
    int i = 0;
    while (i < tam_final) {
        if (vet[i] == val) {
            int j;
            for (j = i; j < tam_final; ++j) {
                vet[j] = vet[j+1];
            }
            --tam_final;
        } else {
            ++i;
        }
    }
    return tam_final;
}

