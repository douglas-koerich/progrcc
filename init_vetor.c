#include <stdlib.h>
#include <stdio.h>

#define TAM_VETOR 5

void imprime(const int vet[], size_t tam) {
    int i;
    for (i=0; i<tam; ++i) {
        printf("%d ", vet[i]);
    }
    putchar('\n');
}

int main(void) {
    int vet1[TAM_VETOR] = { 1, 2, 3, 4, 5 }; // valores iniciais de cada posicao
    imprime(vet1, TAM_VETOR);

    int vet2[TAM_VETOR] = { 1, 2, 3 }; // inicializacao incompleta eh zerada
    imprime(vet2, TAM_VETOR);

    int bad[TAM_VETOR] = { 1, 2, 3, 4, 5, 6 }; // ATENCAO, ERRO! inicializacao
                                               // ALEM DO LIMITE do vetor!!!
    imprime(bad, TAM_VETOR);

    int vet3[] = { 1, 2, 3 }; // tamanho eh DEDUZIDO pelo comprimento da lista
                              // nesse caso, eh como se fosse vet[3]
    imprime(vet3, sizeof(vet3)/sizeof(int)); // sizeof(X): num. de bytes de X

    // Atencao: isto eh C11 (padrao 2011), nem todo compilador suporta!
    int vet11[TAM_VETOR] = { [1] = 3, 7, [4] = 6 };
    imprime(vet11, TAM_VETOR);

    return EXIT_SUCCESS;
}

