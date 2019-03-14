#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float Vi, i, Vf;
    int N;

    printf("Vi? "); scanf("%f", &Vi);
    printf("N? "); scanf("%d", &N);
    printf("i? "); scanf("%f", &i);

    Vf = Vi * pow(1+i, N);

    // Impressao de float com 2 casas apos o ponto decimal
    printf("O rendimento obtido eh $%.2f.\n", Vf-Vi);
    printf("O valor final eh $%.2f.\n", Vf);

    return EXIT_SUCCESS;
}

