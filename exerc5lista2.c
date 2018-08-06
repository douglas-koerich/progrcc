#include <stdio.h>

int main() {
    float salario;  // em reais (com centavos)
    int tempo;      // em anos

    printf("Digite o salario do funcionario (R$): ");
    scanf("%f", &salario);
    printf("Digite o tempo de trabalho na empresa (anos): ");
    scanf("%d", &tempo);

    float bonus, extra = 0.0, total;

    if (salario <= 400.0) {
        bonus = salario * 15 / 100; // (a)
    }
    else {
        if (salario > 400.0 && salario <= 1000.0) {
        /* Poderia fazer apenas este teste: if (salario <= 1000.0),
         * porque para ter vindo ao 'else' obrigatoriamente o salario
         * NAO eh menor ou igual a 400, ou seja, eh maior que 400...
         */
            bonus = salario * 0.12; // (b)
        }
        else {
            bonus = salario * 0.05; // (c)
        }
        /*
        // Operador ternario da decisao
        bonus = salario * salario <= 1000.0? 0.12: 0.05;
        */
    }

    if (tempo >= 3) {
        extra = salario * 0.10;
    }

    total = salario + bonus + extra;

    printf("O salario recebido pelo funcionario sera R$ %.2f\n", total);

    return 0;
}
