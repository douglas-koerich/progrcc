#include <stdlib.h>
#include <stdio.h>

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
        int x, fatorial;
        for (x=fatorial=1; x<=i-1; ++x) {
            fatorial *= x;
        }
        float termo = Y / fatorial;
        P *= termo;
    }

    printf("O produtorio dos %d termos eh igual a %f\n", n, P);

    return EXIT_SUCCESS;
}

