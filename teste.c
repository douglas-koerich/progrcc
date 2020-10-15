#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define TAMANHO 5 // sem ponto-e-virgula

int corrige_teste(char [*], size_t);

int main(void) {
    const size_t NUM_QUESTOES = TAMANHO; // variavel "constante" (nao pode alterar o valor)

    char respostas[NUM_QUESTOES]; // numero de elementos (respostas) do conjunto

    int i;
    for (i = 0; i < NUM_QUESTOES; ++i) {
        printf("Digite a resposta da questao %d a seguir: ", i+1);
        scanf(" %c", &respostas[i]);
    }

    int grau = corrige_teste(respostas, NUM_QUESTOES);

    printf("A sua nota eh %d\n", grau);

    return EXIT_SUCCESS;
}

int corrige_teste(char respostas[], size_t tamanho) {
    char gabarito[TAMANHO] = { 'c', 'a', 'c', 'd', 'e' }; // inicializacao do conjunto (vetor)
                           /*   0    1    2    3    4   */

    int i, nota = 0;

    for (i = 0; i < tamanho; ++i) {
        if (tolower(respostas[i]) == gabarito[i]) {
            ++nota;
        }
    }

    return nota;
}