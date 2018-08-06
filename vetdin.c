#include <stdlib.h>
#include <stdio.h>

int main() {
    // int v[TAM];  --> alocacao estatica, presume uma estimativa do
    //                  tamanho necessario

    printf("Digite o tamanho do vetor: ");
    int tam;
    scanf("%d", &tam);

    /*
    int v[tam]; // essa declaracao NAO EH suportada em todos os compiladores
                // Solucao: alocacao dinamica
    */
    int* v = (int*) malloc(sizeof(int) * tam);  // reservo 'tam' inteiros!

    // Como podemos usar [] e * indiscriminadamente com ponteiros, posso
    // continuar usando o "vetor" (que na verdade eh soh um ponteiro) com
    // o operador de indexacao ([])
    int i;
    for (i=0; i<tam; ++i) {
        printf("Digite o valor do elemento %d do vetor: ", i);
        scanf("%d", &v[i]); // ou scanf("%d", v+i);
    }

    // Calcula a media dos valores
    float media = 0.0;
    /*
    for (i=0; i<tam; ++i, ++v) {    // perdi o ponteiro alocado!!!
    */
    int* p = v;
    for (i=0; i<tam; ++i, ++p) {
        media += *p;
        // Se nao quero um outro ponteiro, devo usar 'v' fixo!
        // media += *(v+i);
    }
    printf("A media dos valores eh %f\n", media/tam);

    // Libera memoria alocada (o vetor)
    free(v);

    return 0;
}

