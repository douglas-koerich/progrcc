#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    // Variaveis de entrada
    float valor_inicial;   // Vi
    unsigned num_periodos; // N
    float taxa;            // i (0 <= i <= 1)

    printf("Informe o valor inicial: ");
    scanf("%f", &valor_inicial); // nao esqueca o & antes da variavel

    printf("Informe o numero de meses/anos em que o valor ficara aplicado: ");
    scanf("%u", &num_periodos);

    printf("Digite a taxa de juros (em percentagem): ");
    scanf("%f", &taxa);
    taxa /= 100; // 15% --> 0.15

    // Variaveis de saida
    float rendimento, valor_final;

    // Calculo do valor final usando a formula
    valor_final = valor_inicial * pow(1 + taxa, num_periodos);
    rendimento = valor_final - valor_inicial;

    printf("O rendimento obtido foi de $ %.2f\n", rendimento);
    printf("O saldo final da aplicacao eh $ %.2f\n", valor_final);

    return EXIT_SUCCESS;
}