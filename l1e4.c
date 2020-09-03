#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    unsigned N; // numero inteiro positivo
    
    printf("Digite um numero inteiro e positivo: ");
    scanf("%u", &N);

    /*
    int num_digitos_N = log10(N) + 1; // atribuicao de real pra inteiro descarta (trunca) apos a virgula
    unsigned digito_mais_significativo = N / pow(10, num_digitos_N - 1);
    */
    unsigned digito_mais_significativo = N / pow(10, (int) log10(N)); // ainda descarta a parte fracionaria
                                                                      // do retorno do logaritmo

    printf("O algarismo mais significativo do numero eh %u\n", digito_mais_significativo); 

    return EXIT_SUCCESS;
}