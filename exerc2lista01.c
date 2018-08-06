#include <stdlib.h>     // EXIT_SUCCESS
#include <stdio.h>      // printf() e scanf()
#include <math.h>       // pow(), sqrt(), log(), etc.

// Bloco principal de codigo (do programa)
int main() {
    // Declaracao das variaveis
    int N;
    float Vf, Vi, i;

    // Entrada de valores/dados
    printf("Digite o valor inicial da aplicacao: ");
    scanf("%f", &Vi);
    printf("Por quantos meses pretende deixar aplicado? ");
    scanf("%d", &N);
    printf("Qual a taxa de juros (percentual): ");
    scanf("%f", &i);

    Vf = Vi * pow(1+i/100, N);

    /*
    float rendimento = Vf - Vi;
    printf("Rendimento no periodo = $%.2f\n", rendimento);
    */
    printf("Rendimento no periodo = $%.2f\n", Vf - Vi);
    printf("Valor ao final da aplicacao = $%.2f\n", Vf);

    return EXIT_SUCCESS;
}
