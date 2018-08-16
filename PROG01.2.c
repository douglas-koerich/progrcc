#include <stdlib.h> // para uso do EXIT_SUCCESS
#include <stdio.h>  // para uso do printf() e do scanf()
#include <math.h>   // para uso de pow()

int main() {
    // Variaveis de entrada
    float Vi, i;
    int N;

    printf("Digite o capital inicial: ");
    scanf("%f", &Vi);
    printf("Quantos meses serao aplicados? ");
    scanf("%d", &N);
    printf("Qual a taxa de juros (%%a.m.)? ");
    scanf("%f", &i);

    // Calculos
    i /= 100; // adequacao da taxa ao intervalo [0,1]: i = i / 100;

    // Variaveis de calculo/saida
    float rendimento, Vf;

    // Aplicacao direta da formula do enunciado
    Vf = Vi * pow(1 + i, N);
    rendimento = Vf - Vi;

    printf("O rendimento apos o periodo serah de %.2f (valor final = %.2f)\n", rendimento, Vf);

    return EXIT_SUCCESS;
}

