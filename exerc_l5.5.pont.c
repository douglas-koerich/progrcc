/* Exercicio 5 da lista PROG 05 usando ponteiro no lugar de vetor, onde:
 * a) O conjunto de elementos ("vetor") deve ser alocado dinamicamente;
 * b) O deslocamento sobre os elementos deve ser feito atraves de aritmetica de
 *    ponteiro.
 */

#include <stdlib.h>
#include <stdio.h>

void remover_n(int, int*, size_t*);

int main(void) {
    size_t tamanho;
    int* vetor;

    printf("Quantos numeros deseja digitar? ");
    scanf("%zd", &tamanho);

    vetor = malloc(tamanho * sizeof(int));
    int i;
    for (i=0; i<tamanho; ++i) {
        printf("Digite o valor para [%d]: ", i);
        scanf("%d", vetor+i);
    }
    int valor;
    printf("Qual numero deseja remover do vetor? ");
    scanf("%d", &valor);

    remover_n(valor, vetor, &tamanho);

    puts("Conteudo final do vetor:");
    for (i=0; i<tamanho; ++i) { // 'tamanho' foi reduzido por remover_n()
        printf("%d ", *(vetor+i));
    }
    printf("(%zd numeros)\n", tamanho); // mostra o novo tamanho

    free(vetor);

    return EXIT_SUCCESS;
}

void remover_n(int val, int* vet, size_t* tam) {
    int i = 0;
    while (i < *tam) {
        if (*(vet+i) == val) {
            int j;
            for (j=i; j<*tam-1; ++j) {
               *(vet+j) = *(vet+j+1);
            }
            --(*tam);   // precisa dos parenteses pra funcionar
                        // (pra que -- se aplique sobre o retorno do *)
        } else {
            ++i;    // soh avanca se nao encontrou o valor nessa posicao
        }
    }
}
