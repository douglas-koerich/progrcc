#include <stdlib.h>
#include <stdio.h>

int main() {
    int populacao_A = 90000000;
    float taxa_A = 0.03;   // 3% (3 por cento = 3 por 100 = 3/100)
    int populacao_B = 200000000;
    float taxa_B = 0.015;
    int anos = 1;
    while (populacao_A < populacao_B) { // enquanto a populacao de A nao alcanca a de B
        populacao_A += populacao_A * taxa_A;    // populacao de A cresce pela sua taxa...
        populacao_B += populacao_B * taxa_B;    // ... e a de B tambem, pela sua propria taxa
        printf("DEBUG: pop_A = %d, pop_B = %d.\n", populacao_A, populacao_B);
        ++anos;
    }
    // Saiu do laco porque A ultrapassou ou igualou B
    printf("Foram necessarios %d anos para que a populacao de A\n"
           "(entao com %d) ultrapassasse a de B (com %d).\n", anos, populacao_A,
           populacao_B);

    return EXIT_SUCCESS;
}
