#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    printf("Digite o valor inicial da aplicacao: ");
    float V_i;
    scanf("%f", &V_i);

    printf("Informe o periodo de aplicacao (em meses): ");
    int N;
    scanf("%d", &N);

    printf("Entre com a taxa de juros (%%a.m.): ");
    float i;
    scanf("%f", &i);

    // Converte a taxa de juros percentual para o intervalo [0,1]
    i /= 100; // i = i / 100;

    float V_f = V_i * pow(1 + i, N);

    printf("O montante final eh %.2f\n", V_f); // no printf nao tem o &!!!

    return EXIT_SUCCESS;
}

