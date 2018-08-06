#include <stdlib.h>
#include <stdio.h>

int main() {
    float salario;
    int tempo;

    printf("Informe o salario do(a) funcionario(a): ");
    scanf("%f", &salario);
    printf("Quantos anos de trabalho dele(a)? ");
    scanf("%d", &tempo);

    float bonus;
    if (salario <= 400) {
        bonus = salario * 15 / 100;
    } else {
        if (salario > 400 && salario <= 1000) {
            bonus = salario * 0.12;
        } else {
            bonus = salario * .05;
        }
    }
    float extra = 0.0;
    if (tempo >= 3) {
        extra = salario * .10;
    }

    float final = salario + bonus + extra;
    printf("O valor a ser recebido eh de %.2f\n", final);

    return EXIT_SUCCESS;
}

