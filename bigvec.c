#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAMANHO 10000000

// Uma variavel tao grande, sem alocacao dinamica, soh pode
// ser global
int vetor[TAMANHO];

int main(void) {
    srand((unsigned) time(NULL));

    /*
    int i, vetor[TAMANHO]; // variaveis locais ficam na "pilha" (stack)
    */
    int i;

    // Alocacao dinamica:
    // Pede ao S.O. (via malloc) uma area de memoria cujo tamanho em
    // bytes eh TAMANHO * comprimento (em bytes) de um elemento
    int* vetor = malloc(TAMANHO * sizeof(int));

    for (i = 0; i < TAMANHO; ++i) {
        int num = rand();
        if (i == 0 || i == TAMANHO-1) { // se primeiro ou ultimo elemento...
            printf("vetor[%d] = %d\n", i, num);
        }
        // Usa o ponteiro "vetor" como se ele fosse de fato um
        // vetor, i.e., aplicando nele o operador [] (indexacao)
        vetor[i] = num;
    }

    // Liberacao (devolucao) da memoria
    free(vetor); // ATENCAO! O valor numerico do endereco que
                 // foi recebido no malloc deve ser usado aqui!!

    return EXIT_SUCCESS;
}

