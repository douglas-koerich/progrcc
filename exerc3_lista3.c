#include <stdlib.h>
#include <stdio.h>

int main() {
    float Y;
    int N;

    printf("Digite o numero que serah usado na serie: ");
    scanf("%f", &Y);
    printf("Quantos termos a serie terah? ");
    scanf("%d", &N);

    int i;
    float P;
    for (i=1, P=1.0; i<=N; ++i) {
        // Calculo do fatorial do denominador
        // (precisa de um laco "interno")
        int denominador = i - 1, fatorial = 1, j;
        for (j=1; j<=denominador; ++j) {
            fatorial *= j;
        }
        float termo = Y / fatorial;
        P *= termo;
    }
    printf("O produtorio (P) vale %f.\n", P);

    return EXIT_SUCCESS;
}

