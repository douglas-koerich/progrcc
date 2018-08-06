#include <stdlib.h>
#include <stdio.h>

void preenche_vetor(int [*], int);
void imprime_vetor(int [*], int);

int main(void) {
    int n; // tamanho do vetor (escolhido pelo usuario)
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Declara o vetor com o tamanho escolhido
    int v[n];

    preenche_vetor(v, n);
    imprime_vetor(v, n);

    int m; // numero de deslocamentos ah esquerda
    printf("Digite o numero de deslocamentos a esquerda: ");
    scanf("%d", &m);

    // Por m vezes (repeticao)...
    int i;
    for (i = 1; i <= m; ++i) {
        // ... desloca cada elemento do vetor uma posicao pra tras,
        // lembrando de salvar aquele elemento do inicio ([0])
        int temp = v[0];
        int j;
        for (j = 1; j < n; ++j) {
            v[j-1] = v[j];
        }
        // Depois de deslocar cada elemento ateh o ultimo, poe aquele
        // que era o primeiro na ultima posicao (que ficou "livre")
        v[n-1] = temp;  // [n-1] eh o ultimo indice valido para um vetor com n elementos
    }
    imprime_vetor(v, n);

    return EXIT_SUCCESS;
}

void preenche_vetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; ++i) {
        printf("Digite o valor para o indice [%d] do vetor: ", i);
        scanf("%d", &vetor[i]);
    }
}

void imprime_vetor(int vetor[], int tamanho) {
    int i;
    for (i = 0; i < tamanho; ++i) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

