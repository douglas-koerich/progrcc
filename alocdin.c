#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define NUM_ELEMENTOS 100

// Alocacao ESTATICA de memoria (variavel global)
int vetor[NUM_ELEMENTOS]; // inicializacao automatica com zeros

int main(void) {
    char r;
    do {
        printf("Deseja gerar um vetor (S/N)? ");
        scanf(" %c", &r);
        r = toupper(r); // conv. para maiuscula
    } while (r != 'S' && r != 'N');
    if (r == 'N') {
        puts("Saindo...");
        return EXIT_SUCCESS;
    }
    srand(time(0));

    // Alocacao ESTATICA de memoria (variavel local na pilha)
    //int vetor1[NUM_ELEMENTOS] = {}; // forca a inicializacao

    // Alocacao DINAMICA de memoria ("variavel" na heap)
    int* vetor2 = malloc(NUM_ELEMENTOS * sizeof(int)); // tamanho em BYTES
    printf("Inicio do \"vetor\" alocado pelo malloc = %p.\n", vetor2);

    int i;
    for (i=0; i<NUM_ELEMENTOS; ++i) {
        /*
        vetor2[i] = rand() % 100 + 1;
        printf("%d ", vetor2[i]);
        */
        *(vetor2 + i) = rand() % 100 + 1;
        printf("%d ", *(vetor2 + i));
        // ++vetor2; /* NAO DEVE ALTERAR O ENDERECO DADO PELO malloc()!!! */
    }
    putchar('\n');

    // Alocacao dinamica requer que seja feita a liberacao tambem por
    // chamada de funcao
    free(vetor2);

    return EXIT_SUCCESS;
}

