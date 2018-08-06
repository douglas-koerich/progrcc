#include <stdlib.h>
#include <stdio.h>

size_t remove_x(int [*], size_t, size_t, int);

#define NUM_ELEMENTOS   10

int main(void) {
    int vetor[NUM_ELEMENTOS] = { 1, 2, 4, 3, 2, 6, 1, 2 };
    int x = 2;
    size_t tamanho_util = NUM_ELEMENTOS - 2;    // oito elementos estao no vetor antes da chamada da funcao
    tamanho_util = remove_x(vetor, NUM_ELEMENTOS, tamanho_util, x);
    printf("O novo tamanho util do vetor eh %zd.\n", tamanho_util);
    int i;
    for (i=0; i<tamanho_util; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

size_t  // Funcao vai devolver o NOVO tamanho util (numero de elementos efetivos no vetor) apos a remocao
    remove_x(int vet[],
             size_t tam_total,  // Capacidade total do vetor (em numero de elementos)
             size_t tam_util,   // Quantas posicoes contiguas estao efetivamente usadas (tam_util <= tam_total)
             int numero         // Numero que sera removido
         ) {
    int i = 0;
    while (i < tam_util) {
        if (vet[i] == numero) { // Encontrou uma ocorrencia do valor a ser removido?
            int j;
            for (j=i; j<tam_util-1; ++j) {  // Daqui (i) ate o penultimo elemento do vetor...
                vet[j] = vet[j+1];  // ... copia do proximo para a posicao atual (j)
            }
            --tam_util; // Desconsidera mais uma posicao removida no laco de percurso
        }
        ++i;
    }
    return tam_util;
}
