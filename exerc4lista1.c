#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    unsigned N;

    printf("Digite o numero N: ");
    scanf("%u", &N);

    unsigned num_algarismos = log10(N) + 1; // copia para unsigned vai truncar a parte fracionaria
    unsigned mais_significativo = N / pow(10, num_algarismos - 1); // p.ex. 137 / 10^(3-1)

    printf("O algarismo mais significativo eh %u\n", mais_significativo);

    return EXIT_SUCCESS;
}

