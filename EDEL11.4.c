#include <stdlib.h>
#include <stdio.h>
#include "EDEL11.4.h"

int main(void) {
    // As duas formas validas de declarar uma variavel do tipo que definimos
    Fracao f1;
    struct fracao f2;

    // Modo de leitura "arriscado", presume que o usuario vai respeitar o formato
    // de entrada com barra (/) entre os numeros...
    printf("Digite a primeira fracao N/D: ");
    scanf("%d/%d", &f1.numerador, &f1.denominador);
    printf("Agora, digite a segunda fracao N/D: ");
    scanf("%d/%d", &f2.numerador, &f2.denominador);

    float soma = (float) f1.numerador / f1.denominador +
                 (float) f2.numerador / f2.denominador; // (float) para divisao REAL
    printf("A soma das fracoes eh %.3f\n", soma);
    float subt = (float) f1.numerador / f1.denominador -
                 (float) f2.numerador / f2.denominador;
    printf("A subtracao da primeira pela segunda eh %.3f\n", subt);

    printf("A multiplicacao delas eh %d/%d\n", f1.numerador*f2.numerador,
           f1.denominador*f2.denominador);
    printf("A divisao da primeira pela segunda eh %d/%d\n", f1.numerador*f2.denominador,
           f1.denominador*f2.numerador);

    return EXIT_SUCCESS;
}

