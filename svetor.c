#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    // Inicializa o gerador de numeros randomicos (aleatorios)
    srand((unsigned) time(0));

    // Vamos declarar o vetor com um tamanho definido pelo usuario (C99)
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    // Preenchemos o vetor com numeros aleatorios de 1 a 20
    int i;
    printf("Vetor gerado: ");
    for (i=0; i<tamanho; ++i) {
        vetor[i] = rand() % 20 + 1;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int soma;
    // Soh de sarro, vou percorrer o vetor no sentido inverso (do ultimo para o primeiro)
    // percurso direto: for (i=soma=0; i<tamanho; ++i) {    // mesmo que: i=0, soma=0
    for (i=tamanho-1, soma=0; i>=0; --i) {
        soma += vetor[i];
    }
    printf("A soma dos elementos eh igual a %d.\n", soma);
}
