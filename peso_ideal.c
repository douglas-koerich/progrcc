#include <stdlib.h>
#include <stdio.h>

/* Crie um programa que leia a altura e o sexo de uma pessoa e imprima o seu
 * peso ideal. Para homens, deverah calcular o peso ideal usando a formula:
 * peso ideal = 72,7 x alt - 58; para mulheres: peso ideal = 62,1 x alt - 44,7. */

int main() {
    float altura;
    char sexo;

    printf("Digite sua altura, em metros: ");
    scanf("%f", &altura);

    // Laco do tipo repita-ate, ou melhor, repita-enquanto
    do {
        printf("Digite seu sexo (M/F): ");
        scanf(" %c", &sexo); // lembre-se do espaco antes do %c!
    } while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f');

    float peso_ideal;
    if (sexo == 'M' || sexo == 'm') {
        peso_ideal = 72.7 * altura - 58;
    } else {
        peso_ideal = 62.1 * altura - 44.7;
    }

    printf("Seu peso ideal eh %.1f\n", peso_ideal);

    return EXIT_SUCCESS;
}

