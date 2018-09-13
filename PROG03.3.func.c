#include <stdlib.h>
#include <stdio.h>

// Declaracao da funcao: prototipo
int calcula_fatorial(int); // define a "assinatura" da funcao:
                           // o tipo do retorno e do(s) seu(s) parametro(s)

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    float Y;
    printf("Digite o valor do numerador (Y): ");
    scanf("%f", &Y);

    int i;
    float P = 1.0;
    for (i=1; i<=n; ++i) { // como diz a formula (i de 1 a n)...
        int fat = calcula_fatorial(i-1);
        float termo = Y / fat;
        P *= termo;
    }

    printf("O produtorio dos %d termos eh igual a %f\n", n, P);

    return EXIT_SUCCESS;
}

int calcula_fatorial(int n) {
    if (n < 0) {
        return 0; // sai da funcao nesta linha
    }
    int x, fatorial;
    for (x=fatorial=1; x<=n; ++x) {
        fatorial *= x;
    }
    return fatorial;
}

