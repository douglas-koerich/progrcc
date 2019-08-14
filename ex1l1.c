#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float Vi, Vf, i;
    unsigned N;

    printf("Digite o valor inicial da aplicacao: ");
    scanf("%f", &Vi);
    printf("Digite a taxa de juros (0 <= i <= 1): ");
    scanf("%f", &i);
    printf("Digite o numero de periodos (meses) da aplicacao: ");
    scanf("%u", &N);

    Vf = Vi * pow(1 + i, N);

    printf("Valor final da aplicacao = %.2f\n", Vf);
    printf("Rendimento no periodo = %.2f\n", Vf - Vi); // usa o resultado na impressao

    return EXIT_SUCCESS;
}

