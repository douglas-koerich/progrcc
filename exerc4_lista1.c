#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    unsigned numero, msd; // "msd" = most-significant digit

    printf("Por favor, se nao for dar trabalho, digite um numero: ");
    scanf("%u", &numero);

    // A funcao logaritmo nos dah a grandeza do numero (potencia de 10),
    // onde a sua parte inteira eh o numero de algarismos menos 1;
    // Por exemplo, log10(20) = 1,... e log10(5412) = 3,...
    int algarismos = log10(numero) + 1; // lembre-se que ao copiar o resultado
                                        // do log (float) para a variavel (int)
                                        // vai haver o truncamento (descarte)
                                        // da parte fracionaria

    msd = numero / pow(10, algarismos - 1); // usa a divisao INTEIRA para extrair
                                            // o MSD dividindo pela potencia de 10
                                            // apropriada ao tamanho do numero

    printf("O digito mais significativo eh %u.\n", msd);

    return EXIT_SUCCESS;
}

