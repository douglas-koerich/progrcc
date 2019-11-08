#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "pessoa.h"

/* Crie um programa que leia a altura e o sexo de uma pessoa e imprima o seu
 * peso ideal. Para homens, deverah calcular o peso ideal usando a formula:
 * peso ideal = 72,7 x alt - 58; para mulheres: peso ideal = 62,1 x alt - 44,7. */

int main(int argc, char* argv[]) {
    struct person fulano; // eh necessario antepor 'struct' com o nome do tipo

    struct person sicrano = { 0.0, '?', 0.0, -1.0, -1.0 }; 
    struct person anonimo = {}; // tudo zerado
    struct person vip = { .sexo = '?', .imc = 1.0 }; // outros campos zerados

    printf("Digite sua altura, em metros: ");
    scanf("%f", &fulano.altura); // nome-da-variavel.nome-do-campo

    do {
        printf("Digite seu sexo (M/F): ");
        scanf(" %c", &fulano.sexo);
        fulano.sexo = toupper(fulano.sexo); // converte pra maiuscula
    } while (fulano.sexo != 'M' && fulano.sexo != 'F');

    fulano.peso_ideal = fulano.sexo == 'M' ? (72.7 * fulano.altura - 58) :
                                             (62.1 * fulano.altura - 44.7);

    printf("Seu peso ideal eh %.1f\n", fulano.peso_ideal);

    return EXIT_SUCCESS;
}

