#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10

int main() {
    srand((unsigned) time(0));  // inicializacao do algoritmo de geracao

    int i, vetor[MAX];

    /*
    vetor[0] = rand();
    vetor[1] = rand();
    vetor[2] = rand();
    vetor[3] = rand();
    ...
    */
    for (i=0; i<MAX; ++i) {  // i serve para:
                            // - controle do laco (numero de repeticoes); e
                            // - indice da posicao em questao neste passo
        vetor[i] = rand();
    }

    // Imprime o vetor
    for (i=0; i<MAX; ++i) {
        printf("vetor[%d]=%d\n", i, vetor[i]);
    }

    return 0;
}
