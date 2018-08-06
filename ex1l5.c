#include <stdlib.h>
#include <stdio.h>

// A funcao eh do tipo "void" porque nao retorna nada, a nao ser o vetor
// preenchido que eh passado como parametro --> passar um vetor como para-
// metro pra uma funcao permite que a mesma altere o seu conteudo, o que
// nao acontece com uma variavel comum (que permanece local e visivel apenas
// na sua funcao de chamada)
void preencheVetor(int [*], size_t);

#define TAM 10

int main(void) {
    int X[TAM], Y[TAM], i;

    // Leitura do primeiro vetor:
    printf("Digitacao dos valores do primeiro vetor:\n");
    preencheVetor(X, TAM);

    // Leitura do segundo vetor:
    printf("Digitacao dos valores do segundo vetor:\n");
    preencheVetor(Y, TAM);

    // Letra (c)
    int S[TAM];
    for (i=0; i<TAM; ++i) {
        S[i] = X[i] + Y[i];
        printf("S[%d] = %d\n", i, S[i]);
    }

    // Letra (d)
    int P[TAM];
    for (i=0; i<TAM; ++i) {
        P[i] = X[i] * Y[i];
        printf("P[%d] = %d\n", i, P[i]);
    }

    return EXIT_SUCCESS;
}

void preencheVetor(int v[], size_t t) {
    int i = 0;
    while (i < t) {
        int temp;
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &temp);
        int j;
        for (j=i-1; j>=0; --j) {
            if (v[j] == temp) {
                printf("Valor duplicado, tente novamente!\n");
                break;  // nao precisa fazer ateh o fim do vetor
            }
        }
        if (j == -1) { // nao encontrou em posicoes anteriores?
            v[i] = temp;
            ++i;    // agora pode ir para ler o proximo
        }
    }
}

