#include <stdlib.h>
#include <stdio.h>

// void min_max_vetor(int [*], size_t, int*, int*);
void min_max_vetor(int*, size_t, int*, int*);

int main(void) {
    int vetor[] = { 1, 4, 3, -3, 0, 6, 2 };
    int m, M;\

    // Repare que se usa uma operacao com sizeof's pra deduzir o numero de
    // elementos do vetor a partir dos tamanhos em bytes
    size_t tamanho = sizeof(vetor)/sizeof(int);
    min_max_vetor(vetor, tamanho, &m, &M);

    printf("O menor valor do vetor eh %d e o maior eh %d.\n", m, M);
    printf("Conteudo do vetor: ");
    int i;
    for (i=0; i<tamanho; ++i) {
        // printf("%d ", vetor[i]);
        printf("%d ", *(vetor+i));  // "vetor", sendo o nome da variavel-vetor, eh CONSTANTE
    }
    putchar('\n');
    return EXIT_SUCCESS;
}

//void min_max_vetor(int v[], size_t t, int* min, int* max) {
void min_max_vetor(int* v, size_t t, int* min, int* max) {  // "v", sendo um ponteiro comum, NAO eh constante
    if (t == 0) {   // vetor de tamanho nulo
        return;
    }
    //*min = *max = v[0];
    *min = *max = *v;
    int i;
    /*
    for (i=0; i<t; ++i) {
        // Ponteiro usado como vetor
        if (v[i] < *min) {
            *min = v[i];
        }
        if (v[i] > *max) {
            *max = v[i];
        }
        // Ponteiro usado como ponteiro
        if (*(v+i) < *min) {
            *min = *(v+i);
        }
        if (*(v+i) > *max) {
            *max = *(v+i);
        }
    }
    */
    // Ponteiro "caminha" pelo vetor dentro do laco
    for (i=0; i<t; ++i, ++v) {
        if (*v < *min) {
            *min = *v;
        }
        if (*v > *max) {
            *max = *v;
        }
    }
}
