#include <stdlib.h>
#include <stdio.h>

int main() {
    float salario_base;
    int tempo_trabalho;

    printf("Digite o salario, em reais: ");
    scanf("%f", &salario_base);
    printf("Digite o tempo de servico, em anos: ");
    scanf("%d", &tempo_trabalho);

    float bonus;
    if (salario_base <= 400.00) {   // (a)
        bonus = salario_base * 15 / 100;    // ou multiplicado por 0.15
    } else {
        if (salario_base > 1000.00) {   // (c)
            bonus = salario_base * 0.05;
        } else {    // (b)
            bonus = salario_base * 0.12;
        }
    }

    float extra;
    if (tempo_trabalho >= 3) {
        extra = salario_base * .10; // aceita nao ter o zero na frente
    } else {
        extra = 0.0;    // nao tem bonus extra
    }

    float salario_final = salario_base + bonus + extra;
    printf("O novo salario eh %.2f (em reais).\n", salario_final);
    
    return EXIT_SUCCESS;
}
