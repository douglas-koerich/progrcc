#include <stdio.h>

int main() {
    float conta;
    int carlos, andre;
    float felipe;

    printf("Digite o valor total da conta (R$): ");
    scanf("%f", &conta);

    // Variaveis 'carlos' e 'andre' recebem o mesmo valor
    // Atencao: essa divisao eh REAL, mas como o destino eh uma variavel
    // INTEIRA, ocorre o truncamento do valor (perde os centavos)
    carlos = andre = conta / 3;

    // Felipe, o Bebado, tem que pagar a diferenca
    felipe = conta - (carlos + andre);

    printf("Os meliantes pagarao os valores: Carlos=R$ %d.00; Andre=R$ %d.00; e Felipe=R$ %.2f\n", carlos, andre, felipe);

    return 0;
}

