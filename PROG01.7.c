#include <stdlib.h>
#include <stdio.h>

int main() {
    float total;
    int carlos, andre;

    printf("Digite o valor total da conta: ");
    scanf("%f", &total);

    float divisao_igual = total / 3;
    carlos = andre = divisao_igual; // truncagem da parte fracionaria

    float felipe = total - (carlos + andre);

    printf("Carlos e Andre pagarao %.2f, e Felipe pagara %.2f\n",
           (float) carlos, felipe); // uso do cast para fazer de 'carlos' uma
                                    // variavel _temporariamente_ do tipo float

    return EXIT_SUCCESS;
}

