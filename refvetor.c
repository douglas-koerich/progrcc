#include <stdlib.h>
#include <stdio.h>

// Chamadas de funcoes com parametro escalar (unico valor)
void nao_altera_escalar(int);
void altera_escalar(int*);

// Chamadas de funcoes com parametro vetor (varios valores)
void nao_altera_vetor_sqn(int [*], size_t);
void nao_altera_vetor_sqn2(int*, size_t);
void forca_nao_alterar_vetor(const int [*], size_t);    // bloquear mudancas na funcao
#define TAM 3

int main(void) {
    int x = 10;

    printf("Antes de 'nao_altera_escalar', x = %d\n", x);
    nao_altera_escalar(x);
    printf("Depois de 'nao_altera_escalar' (antes de 'altera_escalar'), x = %d\n", x);
    altera_escalar(&x);
    printf("Depois de 'altera_escalar', x = %d\n", x);

    int i, v[TAM] = { 1, 2, 3 };
    printf("Antes de 'nao_altera_vetor': ");
    for (i=0; i<TAM; ++i) printf("%d ", v[i]);
    putchar('\n');
    // nao_altera_vetor_sqn(v, TAM);
    nao_altera_vetor_sqn2(v, TAM);
    printf("Depois de 'nao_altera_vetor': ");
    for (i=0; i<TAM; ++i) printf("%d ", v[i]);
    putchar('\n');

    forca_nao_alterar_vetor(v, TAM);

    return EXIT_SUCCESS;
}

void nao_altera_escalar(int i) {    // passagem por copia
    i = 15;
}

void altera_escalar(int* i) {       // passagem por endereco/referencia
    *i = 15;
}

void nao_altera_vetor_sqn(int w[], size_t t) {
    int i;
    for (i=0; i<t; ++i) {
        w[i] = i * 5;
    }
}

void nao_altera_vetor_sqn2(int* w, size_t t) {
    int i;
    for (i=0; i<t; ++i) {
        w[i] = i * 5;   // posso usar [] num ponteiro: w[i] <=> *(w+i)
    }
}

void forca_nao_alterar_vetor(const int w[], size_t t) {
    int i;
    for (i=0; i<t; ++i) {
        // w[i] = i * 5; (essa linha nao compila!!!)
        printf("w[%d] = %d\n", i, w[i]);
    }
}
