#include <stdlib.h>
#include <stdio.h>

int main() {
    int populacao_A, populacao_B;
    float taxa_cresc_A, taxa_cresc_B;

    int anos = 0;

    printf("Populacao de A (em milhares): ");
    scanf("%d", &populacao_A);
    printf("Taxa de crescimento anual de A (%%): ");
    scanf("%f", &taxa_cresc_A);

    printf("Populacao de B (em milhares): ");
    scanf("%d", &populacao_B);
    printf("Taxa de crescimento anual de B (%%): ");
    scanf("%f", &taxa_cresc_B);

    while (populacao_A < populacao_B) {
        populacao_A *= 1 + (taxa_cresc_A / 100);
        populacao_B *= 1 + (taxa_cresc_B / 100);
        ++anos; // equivalente a anos = anos+1 ou anos += 1
    }
    printf("Sera(o) necessario(s) %d ano(s) para A suplantar B.\n", anos);

    return EXIT_SUCCESS;
}

