#include <stdlib.h>
#include <stdio.h>
#include <time.h>

size_t remove_numero(int [*], size_t, int);

int main(void) {
    size_t tamanho;
    printf("Digite o tamanho do vetor de exemplo: ");
    scanf("%zu", &tamanho);

    int vetor[tamanho]; // nao eh possivel em compiladores C89

    // Gera um conteudo aleatorio para o vetor
    srand((unsigned) time(0));
    int indice;
    for (indice = 0; indice < tamanho; ++indice) {
        vetor[indice] = rand() % 10;
        printf("%d ", vetor[indice]);
    }

    int numero;
    printf("\n\nDigite o numero que deseja remover desse conjunto: ");
    scanf("%d", &numero);

    // Atualiza o valor do tamanho com o retorno da funcao
    tamanho = remove_numero(vetor, tamanho, numero);

    printf("Apos a remocao (ou nao) do numero:\n");
    for (indice = 0; indice < tamanho; ++indice) {
        printf("%d ", vetor[indice]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

size_t remove_numero(int vet[], size_t tam, int num) {
    int i = 0;
    while (i < tam) { // fazer ateh o tamanho (atualizado) do vetor
        if (vet[i] != num) { // nao eh o numero procurado?
            ++i; // avanca para a posicao seguinte
        } else {
            int j;
            // A partir da posicao seguinte, desloca cada elemento para
            // a posicao anterior
            for (j = i+1; j < tam; ++j) {
                vet[j-1] = vet[j];
            }
            --tam; // o vetor fica diminuido de um elemento

            // NAO avanca para a posicao seguinte, o elemento que
            // tomou o lugar do numero removido pode ser tambem igual
            // a ele (e por isso deve ser verificado na proxima execucao
            // do laco)
        }
    }
    return tam;
}