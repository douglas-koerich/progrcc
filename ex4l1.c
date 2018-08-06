#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf e scanf
#include <math.h>   // log10 e pow

int main() {
    unsigned N;

    printf("Digite um numero inteiro e positivo: ");
    scanf("%u", &N);

    // Logaritmo de 100 na base 10 eh 2 (porque 10^2 eh 100);
    // Logaritmo de 1000 da base 10 eh 3;
    // Entao qualquer numero de 3 algarismos terah um logaritmo 2,xxx
    int comprimento = log10(N); // a parte inteira do logaritmo eh armazenada
    ++comprimento;  // o numero de algarismos eh um a mais que a parte inteira

    // Para obter o algarismo mais significativo, divido N pela potencia de 10
    // da mesma grandeza (milhar, milhao, etc.), obtida a partir do comprimento
    // do numero
    int grandeza = pow(10, comprimento-1);  // ou a parte inteira do logaritmo
                                            // usada diretamente aqui

    unsigned algarismo_mais_significativo = N / grandeza;  // divisao inteira!!!

    printf("O algarismo mais significativo do numero eh %u\n",
           algarismo_mais_significativo);

    return EXIT_SUCCESS;
}
