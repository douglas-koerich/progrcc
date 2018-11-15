#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 10

int main(void) {
    int vetor[NUM_ELEMENTOS] = { 2, 4, 6, 8, 10, 9, 7, 5, 3, 1 };
    int* pi;
    int i;
    /*
    for (i = 0, pi = vetor; i < NUM_ELEMENTOS; ++i, ++pi) { // pi "caminha" no vetor
    */
    for (i = 0, pi = vetor; i < NUM_ELEMENTOS; ++i) { // pi NAO "caminha" no vetor
        /*
        printf("%d ", vetor[i]); // imprime o i-esimo elemento
        int* pi;
        pi = &vetor[i];
        printf("%d ", *pi);
        printf("%d @ %p\n", *(pi + i), pi + i);
        printf("%d @ %p\n", *(vetor + i), vetor + i);
        */
        printf("%d @ %p\n", pi[i], &pi[i]); // INDEXAR um ponteiro

        /* ATENCAO: a linha abaixo eh um ERRO!
        printf("%d @ %p\n", *vetor, vetor); ++vetor; <-- ISSO NAO EXISTE!
        */
    }
    putchar('\n');
    
    return EXIT_SUCCESS;
}

