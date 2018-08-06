#include <stdlib.h>
#include <stdio.h>
#include "juros.h"

int main(void) {
    double inicial, final, taxa;
    unsigned periodo;
    printf("Digite a divida inicial: ");
    scanf("%lf", &inicial);
    printf("Digite a taxa de juros (%% a.m.): ");
    scanf("%lf", &taxa);
    printf("Digite o periodo (meses): ");
    scanf("%u", &periodo);

    final = valor_final(inicial, taxa, periodo);

    printf("Apos %u meses, sua divida eh de %.2lf.\n", periodo, final);

    return EXIT_SUCCESS;
}
