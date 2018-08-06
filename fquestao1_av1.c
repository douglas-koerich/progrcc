#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int potencia;
    if (argc < 2) {
        potencia = 2;
    } else {
        potencia = atoi(argv[1]);
    }
    float X, Y = 1, lucro_total, lucro_diario = 0.0;
    int operarios_standard, operarios_luxo, radios_standard, radios_luxo;

    FILE* arquivo = fopen("/tmp/analise.txt", "w");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return EXIT_FAILURE;
    }
    for (X = pow(10, -potencia); X <= pow(10, potencia); X += pow(10, -potencia)) {
        int num_operarios_luxo;
        for (num_operarios_luxo = 16; num_operarios_luxo <= 32; ++num_operarios_luxo) {
            float lucro = X * (40 - num_operarios_luxo) + 0.5 * Y * num_operarios_luxo;
            if (lucro > lucro_diario) {
                lucro_diario = lucro;
                operarios_standard = 40 - num_operarios_luxo;
                operarios_luxo = num_operarios_luxo;
            }
        }

        radios_standard = operarios_standard * 22;
        radios_luxo = operarios_luxo * 11;
        lucro_total = X * radios_standard + Y * radios_luxo;

        fprintf(arquivo, "X=%.3f, Y=%.0f, opstd=%d, std=%d, oplux=%d, lux=%d, lucro=%.2f\n",
                X, Y, operarios_standard, radios_standard, operarios_luxo, radios_luxo,
                lucro_total);
    }
    fclose(arquivo);

    return EXIT_SUCCESS;
}

