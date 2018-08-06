#include <stdlib.h>
#include <stdio.h>

void limpa_ocorrencias(int*, size_t*, int);

#define MAX 15

int main(void) {
    int i, vetor[MAX] = { 2, 4, 6, 8, 2, 6, 7, 9, 2 };
    size_t tamanho = 9; // numero de elementos inicializados no vetor
                        // (tamanho "util" do vetor)

    printf("O vetor original: ");
    for (i=0; i<tamanho; ++i) {     // ateh a ultima posicao util (tamanho-1)
        printf("%d ", vetor[i]);
    }
    putchar('\n');

    int referencia = 6; // numero a ser removido do vetor

    // A funcao limpa_ocorrencias vai alterar as duas variaveis, 'vetor' e 'tamanho'
    // Note que 'vetor' sendo uma variavel-vetor (e "ponteiro"), nao tem & na frente,
    // mas 'tamanho' precisa do & por ser uma variavel escalar
    limpa_ocorrencias(vetor, &tamanho, referencia);

    printf("O vetor agora ficou com: ");
    for (i=0; i<tamanho; ++i) { // note que o tamanho "util" diminuiu apos a funcao
        printf("%d ", vetor[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

void limpa_ocorrencias(int* vet, size_t* tam, int ref) {
    int ind = 0;
    while (ind < *tam) {
        if (*(vet+ind) == ref) {
            int ind2 = ind;
            while (ind2 < *tam-1) {
                *(vet+ind2) = *(vet+ind2+1);
                ++ind2;
            }
            *tam = *tam - 1;
        }
        else {
            ++ind;
        }
    }
}

