#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 10

int main(void) {
    int vetor[NUM_ELEMENTOS];
    int i;
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        vetor[i] = i;
        printf("%d ", vetor[i]);
    }
    putchar('\n');

    /* Variante 1
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        int* p = &vetor[i];
        printf("%d ", *p);
    }
    */
    /* Variante 2
    int* p = &vetor[0];
    for (i = 0; i < NUM_ELEMENTOS; ++i) { //, ++p) {
        printf("%d ", *p++);
        // ++p;
    }
    putchar('\n');
    */
    /* Variante 3 (apenas uma mudanca em relacao a 2)
    int* p = vetor;
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        printf("%d ", *p++);
    }
    putchar('\n');
    */
    /* Variante 4
    int* p = vetor;
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        printf("%d ", *(p + i));
    }
    putchar('\n');
    */
    /* Variante 5
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        printf("%d ", *(vetor + i));
    }
    putchar('\n');
    */
    // Variante 6
    int* p = vetor;
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        printf("%d ", p[i]);
    }
    putchar('\n');
    /* Variante 7: ERRADA!!
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        printf("%d ", *vetor++); // ERRO! 'vetor' eh um ponteiro CONSTANTE!
    }
    putchar('\n');
    */

    return EXIT_SUCCESS;
}

