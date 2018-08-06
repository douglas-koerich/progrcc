#include <stdlib.h>
#include <stdio.h>  // arquivo-cabecalho do sistema (instalado com o compilador) usa <>
#include "juros.h"  // arquivo-cabecalho desenvolvido por nos usa "" e fica no mesmo diretorio dos *.c

int main(void) {
    double inicial, final, taxa;
    unsigned periodo;
    printf("Digite o investimento inicial: ");
    scanf("%lf", &inicial);
    printf("Digite a taxa de juros (%% a.m.): ");
    scanf("%lf", &taxa);
    printf("Digite o tempo de aplicacao (meses): ");
    scanf("%u", &periodo);

    final = valor_final(inicial, taxa, periodo);

    printf("Apos %u meses, seu saldo eh de %.2lf.\n", periodo, final);

    return EXIT_SUCCESS;
}
