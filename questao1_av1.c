#include <stdlib.h>
#include <stdio.h>

int main(void) {
    float X, Y, lucro_total, lucro_diario = 0.0;
    int operarios_standard, operarios_luxo, radios_standard, radios_luxo;

    printf("Digite o lucro com radio standard: ");
    scanf("%f", &X);
    printf("Digite o lucro com radio luxo: ");
    scanf("%f", &Y);

    int num_operarios_luxo;
    for (num_operarios_luxo = 16; num_operarios_luxo <= 32; ++num_operarios_luxo) {
        float lucro = X * (40 - num_operarios_luxo) + 0.5 * Y * num_operarios_luxo;
        if (lucro > lucro_diario) {
            lucro_diario = lucro;
            operarios_standard = 40 - num_operarios_luxo;
            operarios_luxo = num_operarios_luxo;
        }
        printf("op_luxo = %d, op_standard = %d, lucro = %f\n", num_operarios_luxo,
               40-num_operarios_luxo, lucro);
    }

    radios_standard = operarios_standard * 22;
    radios_luxo = operarios_luxo * 11;
    lucro_total = X * radios_standard + Y * radios_luxo;

    printf("%d operarios na linha standard produzindo %d radios\n",
           operarios_standard, radios_standard);
    printf("%d operarios na linha luxo produzindo %d radios\n", operarios_luxo,
           radios_luxo);
    printf("O lucro total da producao mensal eh R$ %.2f\n", lucro_total);

    return EXIT_SUCCESS;
}

