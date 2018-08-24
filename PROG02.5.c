#include <stdlib.h>
#include <stdio.h>

int main() {
    float salario;
    int tempo_de_casa;

    printf("Digite o salario bruto: ");
    scanf("%f", &salario);
    printf("Digite o tempo de casa do funcionario: ");
    scanf("%d", &tempo_de_casa);

    float bonus;
    if (salario <= 400.0) {
        bonus = salario * 15 / 100;
    } else {
        // if (salario > 400.0 && salario <= 1000.0) {
        if (salario <= 1000.0) {   // estando no bloco do else de cima,
                                   // subentende-se que eh > 400
            bonus = salario * 0.12;
        } else {
            bonus = salario * .05; // parte inteira subentendida como 0
        }
    }

    /*
    float extra = 0.0;
    if (tempo_de_casa >= 3) {
        extra = salario * 10 / 100;
    }
    */
    float extra = tempo_de_casa >= 3? salario * 10 / 100: 0.0; // substitui um if-else aqui

    salario += bonus + extra; // += indica que estah somando ao salario

    printf("O salario final eh %.2f\n", salario);
    
    return EXIT_SUCCESS;
}

