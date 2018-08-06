#include <stdlib.h>
#include <stdio.h>

int main() {
    float salario;
    unsigned tempo;

    printf("Digite o salario do funcionario, em reais: ");
    scanf("%f", &salario);
    printf("Digite o tempo de trabalho do funcionario, em anos: ");
    scanf("%u", &tempo);

    float bonus;
    if (salario <= 400.0) {
        bonus = salario * 15 / 100; // como salario*15 eh feito antes, a divisao eh real!
    }
    else if (salario <= 1000.0) {
        bonus = salario * 0.12; // percentagem em valor absoluto
    }
    else {
        bonus = salario * .05;  // pode ser omitido o 0 (zero) antes do ponto decimal
    }

    float extra = 0.0;  // variavel inicializada com zero, para nao precisar do else abaixo
    if (tempo >= 3) {
        extra = salario * 10 / 100;
    }

    float total = salario + bonus + extra;
    printf("O salario final do funcionario serah de R$ %.2f\n", total); // com 2 casas

    return EXIT_SUCCESS;
}
