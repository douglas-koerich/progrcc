#include <stdlib.h>
#include <stdio.h>

void operacao(int*);
void troca(int*, int*);

int a;  // variavel global (o seu endereco eh conhecido por todas as funcoes)

int main(void) {
    int b;  // variavel local (esse endereco soh eh conhecido por main)

    a = 0;
    printf("O valor original de a eh %d.\n", a);
    printf("Digite o valor da variavel b: ");
    scanf("%d", &b);

    operacao(&b);

    printf("O valor de a agora eh %d e b tornou-se %d.\n", a, b);

    int x, y;
    printf("Digite x: ");
    scanf("%d", &x);
    printf("Agora, digite y: ");
    scanf("%d", &y);

    troca(&x, &y);

    printf("Apos a troca: x = %d, y = %d.\n", x, y);
    
    return EXIT_SUCCESS;
}

void operacao(int* b) {
    a = *b * 10;
    *b = 0;
}

void troca(int* i, int* j) {
    int aux = *i;
    *i = *j;
    *j = aux;
}


