#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int n;
    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    // Cria-se um vetor com o tamanho indicado pelo usuario
    // int vetor[n];   // Soh eh possivel a partir do C99

    // Pede ao sistema operacional que crie uma "variavel-vetor" na heap
    // (alocacao dinamica de um bloco de memoria)
    int* vetor = malloc(n * sizeof(int));    // parametro = numero de BYTES total

    // Como se pode usar o ponteiro 'vetor' como se fosse uma variavel-vetor
    // (inclusive usando colchetes [] para indexar), tudo ocorre como se
    // eu tivesse um vetor declarado pelo meu programa
    int i = 0;
    while (i < n) {
        printf("Digite um valor a ser armazenado: ");
        scanf("%d", vetor + i); // lembre-se: vetor+i <=> &vetor[i]
        ++i;
    }

    // Imprime os valores digitados
    /*
    for (i=0; i<n; ++i) {
        printf("vetor[%d]=%d\n", i, vetor[i]); // vetor[i] <=> *(vetor+i)
    }
    */
    /*
    // ISSO DAH ERRO!!!
    for (i=0; i<n; ++i, ++vetor) {
        printf("vetor[%d]=%d\n", i, *vetor);
    }
    */
    // Entao resolve assim
    int* vetor2 = vetor;
    for (i=0; i<n; ++i, ++vetor) {
        printf("vetor[%d]=%d\n", i, *vetor);
    }

    free(vetor2);    // deve ser o MESMO valor recebido pelo malloc
    return EXIT_SUCCESS;
}

