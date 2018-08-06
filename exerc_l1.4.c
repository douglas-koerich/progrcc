#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    unsigned N; // "Dado um inteiro POSITIVO N, ..."

    printf("Digite o numero (N): ");
    scanf("%u", &N);

    /*
    int potencia_10 = log10(N); // a conversao de double pra int eh util
                                // aqui, pois descarta a parte fracionaria
    int divisor = pow(10, potencia_10); // de novo, descarta parte fracionaria
    int algarismo_mais_significativo = N / divisor; // divisao inteira!
    */
    int algarismo_mais_significativo = N / pow(10, (int) log10(N));
    // (Foi necessario fazer o "cast" do expoente para (int) a fim de remover
    // a parte fracionaria obtida atraves do log10

    printf("O algarismo mais significativo do numero eh %d\n",
        algarismo_mais_significativo);

    return EXIT_SUCCESS;
}
