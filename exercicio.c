/* Escreva uma funcao que receba tres variaveis como parametros, uma para
   temperaturas em graus Celsius, outra para temperaturas em graus Fahrenheit e
   a terceira para temperaturas em Kelvin. Um quarto parametro, inteiro de 1 a 3,
   indica qual o parametro anterior que deve ser usado como "valor a ser convertido"
   para os outros dois. Exemplo: ao receber 2 nessa variavel, indica que o valor
   em Fahrenheit (2) deve ser convertido para Celsius (1) e Kelvin (3).
   As formulas de conversao sao:
   C = K - 273
   C = 5*(F - 32)/9 */

#include <stdlib.h>
#include <stdio.h>

void converte_temp(int, float*, float*, float*);

int main(void) {
    float celsius, fahrenheit, kelvin, temperatura;
    printf("Digite a temperatura que deseja converter: ");
    scanf("%f", &temperatura);
    int opcao;
    do {
        puts("Digite a unidade de medida da temperatura digitada:");
        puts("  1. Celsius");
        puts("  2. Fahrenheit");
        puts("  3. Kelvin");
        printf("> ");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 3);
    switch (opcao) {
        case 1: celsius = temperatura; break;
        case 2: fahrenheit = temperatura; break;
        case 3: kelvin = temperatura; break;
    }
    // chamada da funcao...
    converte_temp(opcao, &celsius, &fahrenheit, &kelvin);

    puts("As temperaturas nas diferentes unidades sao:");
    printf("Celsius = %f graus\n", celsius);
    printf("Fahrenheit = %f graus\n", fahrenheit);
    printf("Kelvin = %f\n", kelvin);

    return EXIT_SUCCESS;
}

void converte_temp(int origem, float* pC, float* pF, float* pK) {
    switch (origem) {
        case 1:
            *pF = 9*(*pC)/5 + 32;
            *pK = *pC + 273;
            break;

        case 2:
            *pC = 5*(*pF - 32)/9;
            *pK = *pC + 273;
            break;

        case 3:
            *pC = *pK - 273;
            *pF = 9*(*pC)/5 + 32;
            break;
    }
}
