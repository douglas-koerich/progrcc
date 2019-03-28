#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned long long pop_A = 90000000;
    float taxa_A = 0.03; // 3% a.a.
    unsigned long long pop_B = 200000000;
    float taxa_B = 0.015; // 1,5% a.a.

    int anos = 0;
    while (pop_A < pop_B) {
        ++anos;
        pop_A += pop_A * taxa_A;
        pop_B *= (1 + taxa_B); // 1 = 100%
    }
    printf("Serao necessarios %d anos para A atingir/ultrapassar B\n"
           "(populacao de A = %llu, de B = %llu)\n", anos, pop_A, pop_B);

    return EXIT_SUCCESS;
}

