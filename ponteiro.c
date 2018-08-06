#include <stdlib.h>
#include <stdio.h>

#define TAM 10

int main(void) {
    int x = 10;
    int *ponteiro = &x;

    char c = 'Y';
    char* pc = NULL;

    printf("x = %d\n", x);

    printf("Digite um novo valor para x: ");
    //scanf("%d", &x);
    scanf("%d", ponteiro);  // sem o &, porque jah eh o endereco

    printf("O novo valor de x eh %d que estah no endereco %p\n", *ponteiro, ponteiro);

    pc = &c;
    printf("O caractere eh %c\n", *pc);

    int vetor[TAM] = { 1, [2]=5, [5]=8, 15 };
    ponteiro = &vetor[0];
    printf("%d@%p ", *ponteiro, ponteiro);
    printf("%d@%p ", *(ponteiro+2), ponteiro+2);
    ponteiro += 5;
    printf("%d@%p ", *ponteiro, ponteiro);
    ++ponteiro;
    printf("%d@%p\n", *ponteiro, ponteiro);

    puts("Conteudo do vetor:");
    int i;
    //for (i=0, ponteiro=&vetor[0]; i<TAM; ++i, ++ponteiro) {
    //    printf("%d ", *ponteiro);
    ponteiro=&vetor[0];
    for (i=0; i<TAM; ++i) {
        printf("%d ", *ponteiro++);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
