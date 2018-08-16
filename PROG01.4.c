#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    unsigned N; // unsigned int N;

    printf("Digite o valor de N: ");
    scanf("%u", &N); // %u para unsigned int

    int algarismos = log10(N) + 1; // log10 produz um numero real, cuja
                                   // parte inteira eh uma unidade a menos
                                   // do numero de algarismos
    int grandeza = algarismos - 1; // a potencia de 10 que usaremos para extrair
                                   // por divisao inteira o algarismo mais significativo

    int MSD = N / pow(10, grandeza); // MSD = "most significant digit"

    printf("O algarismo mais significativo de %u eh %d.\n", N, MSD);

    return EXIT_SUCCESS;
}

