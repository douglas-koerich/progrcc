#include <stdlib.h>
#include <stdio.h>

int main() {
    float fixo, vendas;         // variaveis de entrada
    float comissao, salario;    // variaveis de calculo e saida

    printf("Digite o salario fixo do funcionario: ");
    scanf("%f", &fixo);
    printf("Digite o montante de vendas dele(a): ");
    scanf("%f", &vendas);

    comissao = vendas * 4 / 100;    // comissao = vendas * 0.04; (ou .04)
    salario = fixo + comissao;

    printf("O funcionario recebera %.2f, sendo %.2f em comissao\n",
        salario, comissao);

    return EXIT_SUCCESS;
}

