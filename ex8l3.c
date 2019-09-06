#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned long long populacao_A, populacao_B;
    float taxa_A, taxa_B;

    printf("Digite a populacao do pais menos populoso (A): ");
    scanf("%llu", &populacao_A);
    printf("Taxa de crescimento desse pais (em %%): ");
    scanf("%f", &taxa_A);

    printf("Digite a populacao do pais mais populoso (B): ");
    scanf("%llu", &populacao_B);
    printf("Taxa de crescimento desse pais (em %%): ");
    scanf("%f", &taxa_B);

    unsigned anos = 0;
    taxa_A /= 100;
    taxa_B /= 100;

    while (populacao_A < populacao_B) {
        populacao_A *= 1 + taxa_A;
        populacao_B *= 1 + taxa_B;
        ++anos;
    }

    printf("Foram necessarios %u anos para A igualar ou superar B\n", anos);
    printf("Pop. final A = %llu; pop. final B = %llu\n",
           populacao_A, populacao_B);

    return EXIT_SUCCESS;
}

