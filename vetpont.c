#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 10

int main(void) {
    int vetor_i[NUM_ELEMENTOS];

    int i;
    /*
    // int* pi = &vetor_i[0];
    int* pi = vetor_i;  // 'vetor_i' eh um "ponteiro constante" par o inicio do vetor

    for (i=0; i<NUM_ELEMENTOS; ++i, ++pi) {
        printf("Digite um numero para armazenar no vetor (endereco=%p): ", pi);

        // scanf("%d", &vetor_i[i]);
        // pi = &vetor_i[i];
        scanf("%d", pi);
    }
    */
    /* Usando o vetor_i diretamente...
    for (i=0; i<NUM_ELEMENTOS; ++i) {
        printf("Digite um numero para armazenar no vetor: ");
        scanf("%d", vetor_i + i);
    }
    */
    int* pi = vetor_i;
    for (i=0; i<NUM_ELEMENTOS; ++i) {
        printf("Digite um numero para armazenar no vetor (endereco=%p): ", pi+i);
        // scanf("%d", pi+i); // usando pi no lugar de vetor_i acima...
        scanf("%d", &pi[i]);
    }

    puts("Sequencia invertida dos elementos no vetor:");
    /*
    pi = vetor_i + (NUM_ELEMENTOS-1);

    for (i=NUM_ELEMENTOS-1, pi=&vetor_i[NUM_ELEMENTOS-1]; i>=0; --i, --pi) {
        // printf("%d ", vetor_i[i]);
        // pi = &vetor_i[i];
        printf("%d@%p ", *pi, pi);
    }
    */
    /* Usando o vetor_i diretamente...
    for (i=NUM_ELEMENTOS-1; i>=0; --i) {
        printf("%d ", *(vetor_i + i));  // nao eh possivel fazer vetor_i++ ou vetor_i--
    }
    */
    pi = vetor_i;
    for (i=NUM_ELEMENTOS-1; i>=0; --i) {
        // printf("%d@%p ", *(pi+i), pi+i);
        printf("%d@%p ", pi[i], pi+i);
    }

    putchar('\n');

    return EXIT_SUCCESS;
}

