#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    unsigned N; // apenas numeros positivos

    printf("Digite o numero a ser inspecionado: ");
    scanf("%u", &N);    // %u -> unsigned!

    unsigned num_algarismos_N = log10(N) + 1;   // double -> int : TRUNCA!
    unsigned divisor = pow(10, num_algarismos_N - 1);
    unsigned mais_significativo = N / divisor;  // divisao inteira!

    printf("O algarismo mais significativo de %u eh %u.\n", N, mais_significativo);

    return EXIT_SUCCESS;
}
