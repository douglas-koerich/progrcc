#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero invalido de parametros!");
        printf("Use: %s <num-elem-vetor>\n", argv[0]);
        return EXIT_FAILURE;
    }
    srand((unsigned) time(NULL));
    size_t tamanho = atoi(argv[1]);

    /*
    // Declaracao de vetor com tamanho variavel
    int vetor[tamanho]; // isso eh valido a partir do C99
    */

    if (tamanho <= 0) {
        return EXIT_FAILURE;
    }
    // "Vetor" alocado dinamicamente:
    // 1. Pede ao SO um bloco de N bytes = tamanho x 4
    //    'vetor' nao eh um vetor na pratica, eh soh um ponteiro
    //    com o endereco do inicio do bloco alocado
    int* vetor = malloc(tamanho * sizeof(int));

    // 2. Usa o bloco como se fosse um vetor...
    int i;
    int* v;
    for (i=0, v=vetor; i<tamanho; ++i) { // nao perde o endereco dado por malloc!
        /*
        vetor[i] = rand() % 10000;
        printf("%d ", *(vetor+i));
        */
        *v = rand() % 10000;
        printf("%d ", *v);
        ++v; // desloca-se para o proximo 'int' no bloco
    }
    putchar('\n');

    // 3. Libera o bloco de memoria
    free(vetor); // deve ser o MESMO endereco recebido no malloc()

    return EXIT_SUCCESS;
}

