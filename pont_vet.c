#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEM 10

int main(void) {
    int vetor[NUM_ELEM];
    
    int i;
    for (i = 0; i < NUM_ELEM; ++i) {
        vetor[i] = i + 1;
    }

    /* 2. Usando um ponteiro declarado fora do laco
    int* p = &vetor[0];
    */

    /* 3, 4 e 6. Usando um ponteiro inicializado com o "ponteiro" vetor */
    int* p = vetor; // soh o nome da variavel-vetor eh o seu endereco inicial
    //*/

    for (i = 0; i < NUM_ELEM; ++i) {
        /* 0. Forma original sem ponteiros
        int num = vetor[i];
        */

        /* 1. Usando um ponteiro declarado dentro do laco
        int* p = &vetor[i];
        int num = *p;
        */

        /* 2 e 3 (cont.). Aritmetica de ponteiro
        printf("\nO ponteiro vale %p\n", p);
        int num = *p;
        ++p; // poderia ser colocado com o ++i dentro do for()
        */

        /* 4. Ponteiro fixo no inicio
        printf("\nO ponteiro continua valendo %p\n", p);
        int num = *(p + i);
        */

        /* 5. "Sem as maos", ou melhor, sem o ponteiro
        int num = *(vetor + i);
        */

        // 6. Indexacao de ponteiro
        int num = p[i];

        printf("%d ", num);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

