#include <stdlib.h>
#include <stdio.h>

#define TAM_VETOR   10

int main(void) {
    int i, vet[TAM_VETOR] = { 1, 2, 3, [6] = 4, 5, 6 };
    /* Versao original
    int *p = &vet[0];
    for (i = 0; i < TAM_VETOR; ++i) {
        printf("%d ", *p);
        ++p;
    }
    */
    /* Mudanca cosmetica (de lugar)
    int *p;
    for (i = 0, p = &vet[0]; i < TAM_VETOR; ++i, ++p) {
        printf("%d ", *p);
    }
    */
    /* Sobreposicao de operadores no ponteiro (*p++)
    int *p = &vet[0];
    for (i = 0; i < TAM_VETOR; ++i) {
        printf("%d ", *p++);
    }
    */
    /* Uso do nome do vetor como endereco!!!
    int *p = vet;   // O nome da variavel-vetor eh um ponteiro para o seu inicio
    for (i = 0; i < TAM_VETOR; ++i, ++p) {
        printf("%d ", *p);
    }
    */
    /* Fixa o ponteiro e percorre o vetor por deslocamento relativo (+i)
    int *p;
    for (i = 0, p = vet; i < TAM_VETOR; ++i) {
        printf("%d ", *(p+i));
    }
    */
    /* Usando o nome do vetor numa expressao como se fosse um ponteiro...
    for (i = 0; i < TAM_VETOR; ++i) {
        printf("%d ", *(vet+i));
    }
    */
    int *p;
    for (i = 0, p = vet; i < TAM_VETOR; ++i) {
        printf("%d ", p[i]);    // indexacao de ponteiro
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

