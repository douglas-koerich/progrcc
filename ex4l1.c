#include <stdlib.h>
#include <stdio.h>
#include <math.h> // para conhecer log10 e pow

int main() {
    unsigned N, MSD; // MSD = most-significant digit

    printf("Oi, usuario(a), digite um numero, por favor: ");
    scanf("%u", &N);

    /*
    // O logaritmo de um numero nos diz a grandeza dele
    unsigned num_digitos = log10(N) + 1; // p.ex. log10(20) = 1.301...
                                         // atribuido a uma 'unsigned' pra ficar
                                         // soh com a parte inteira

    unsigned divisor = pow(10, num_digitos - 1); // a potencia de 10 que
                                                 // eh comparavel a N e que
                                                 // pode extrair o MSD
    MSD = N / divisor; // note que eh uma divisao INTEIRA
    */

    // Numa unica expressao, usando "casting"
    MSD = N / (unsigned)(pow(10, (unsigned)(log10(N)+1) - 1));

    printf("O digito mais significativo do "  // faca assim pra separar
           "seu numero eh %u.\nAteh logo!\n", // a mesma string entre linhas
           MSD);

    return EXIT_SUCCESS;
}

