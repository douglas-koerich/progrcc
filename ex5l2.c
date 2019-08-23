#include <stdlib.h>
#include <stdio.h>

int main() {
    float salario;
    printf("Digite o salario-base do funcionario: ");
    scanf("%f", &salario);

    float bonus;
    if (salario <= 400) {
        bonus = 0.15; // 15%
    } else {
        if (salario > 400 && salario <= 1000) {
        // Poderia ser apenas: if (salario <= 1000)
            bonus = .12; // 12%
        } else { // subentende-se que aqui estao os salarios maiores que 1000
            bonus = 0.05;
        }
    }

    int tempo;
    printf("Digite o tempo de casa (em anos): ");
    scanf("%d", &tempo);

    float extra = 0;
    if (tempo > 3) {
        extra = 0.1;
    }

    float total = salario + salario * bonus + salario * extra;
    // total = salario * (1 + bonus + extra);
    
    printf("O salario final do funcionario eh R$ %.2f\n", total);

    return EXIT_SUCCESS;
}

