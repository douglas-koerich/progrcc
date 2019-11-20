#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NUM 10

// void imprime_vetor(const int [*], size_t);
void imprime_vetor(const int*, size_t); // o que de fato a funcao eh/recebe
                                        // (um ponteiro)
                                        // com 'const' o ponteiro nao pode alterar
                                        // o valor

int main(void) {
    // Um programa estupido que nao faz nada de util...
    
    srand((unsigned) time(0)); // usa o tick atual do relogio como semente

    int vetor[NUM], i;

    /*
    for (i = 0; i < NUM; ++i) {
        // vetor[i] = rand() % 100 + 1; // gera um numero entre 1 e 100
        int* p = &vetor[i]; // salva o endereco do elemento em questao (em i)
        *p = rand() % 100 + 1; // altera o conteudo no endereco com um novo valor
    }
    */

    /*
    int* p;
    // for (i = 0, p = &vetor[0]; i < NUM; ++i, ++p) { // aritmetica de ponteiros
    for (i = 0, p = vetor; i < NUM; ++i, ++p) {
        printf("Alterando o valor no endereco %p...\n", p);
        *p = rand() % 100 + 1;
    }
    */

    // int* p = vetor; // salva em p o endereco do primeiro elemento do vetor
    for (i = 0; i < NUM; ++i) {
        // *(p + i) = rand() % 100 + 1;
        *(vetor + i) = rand() % 100 + 1;
    }

    imprime_vetor(vetor, NUM);

    return EXIT_SUCCESS;
}

// void imprime_vetor(int v[], size_t n) {
void imprime_vetor(const int* v, size_t n) {
    int i;
    putchar('\n');
    for (i = 0; i < n; ++i) {
        printf("%d ", v[i]); // colchetes aplicado a ponteiro
                             // v[i] <==> *(v+i)
    }
    putchar('\n');
}

