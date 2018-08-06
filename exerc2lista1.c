#include <stdio.h>
#include <math.h>

int main() {
    float Vi, Vf, i;
    int N;

    printf("Digite o valor inicial (R$): ");
    scanf("%f", &Vi);

    /*
    // Para imprimir o simbolo de percentagem usando printf, deve fazer %%
    printf("Digite a taxa de juros (nao percentagem, entre 0 e 1 (100%%)): ");
    scanf("%f", &i);
    */

    // Alternativa: taxa de juros entrada em percentagem
    printf("Digite a taxa percentual de juros (0%%-100%%): ");
    scanf("%f", &i);

    i /= 100; // i = i / 100;

    printf("Digite o numero de meses da aplicacao: ");
    scanf("%d", &N);

    Vf = Vi * pow(1+i, N);

    float rendimento = Vf - Vi;

    printf("O rendimento foi de R$ %.2f dando como valor final R$ %.2f\n", rendimento, Vf);

    return 0;
}

