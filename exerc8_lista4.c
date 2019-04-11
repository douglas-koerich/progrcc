#include <stdlib.h>
#include <stdio.h>

int menor_valor(int, int, int, int, int);

int main(void) {
    int n1, n2, n3, n4, n5;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &n3);
    printf("Digite o quarto numero: ");
    scanf("%d", &n4);
    printf("Digite o quinto numero: ");
    scanf("%d", &n5);

    int menor = menor_valor(n1, n2, n3, n4, n5);

    printf("O menor valor eh %d.\n", menor);

    return EXIT_SUCCESS;
}

int menor_valor(int a, int b, int c, int d, int e) {
    int m = a;
    if (b < m) {
        m = b;
    }
    if (c < m) {
        m = c;
    }
    if (d < m) {
        m = d;
    }
    if (e < m) {
        m = e;
    }
    return m;
}

