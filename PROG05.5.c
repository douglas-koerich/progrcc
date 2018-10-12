#include <stdlib.h>
#include <stdio.h>

int main(void) {
    size_t n;
    printf("Qual o tamanho do vetor a ser usado como exemplo? ");
    scanf("%zd", &n);

    int vetor[n], i;
    for (i=0; i<n; ++i) {
        printf("Valor no indice %d? ", i);
        scanf("%d", &vetor[i]);
    }
    puts("ANTES:");
    for (i=0; i<n; ++i) {
        printf("%d ", vetor[i]);
    }
    putchar('\n');

    printf("Qual o valor a ser removido? ");
    int x;
    scanf("%d", &x);

    for (i=0; i<n; ) {
        // Encontrei o valor no vetor?
        if (vetor[i] == x) {
            int j;
            // Da posicao onde encontrei em diante, desloca todo
            // mundo uma posicao para tras...
            for (j=i+1; j<n; ++j) { // j = i+1: "da posicao em diante"
                vetor[j-1] = vetor[j];
            }
            --n; // existe um elemento a menos no vetor
        } else {
            ++i; // soh vou para o proximo se nao desloquei
        }
    }
    puts("DEPOIS:");
    for (i=0; i<n; ++i) {
        printf("%d ", vetor[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

