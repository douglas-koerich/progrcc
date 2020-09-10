#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double operando_1, operando_2;

    printf("Digite um primeiro numero: ");
    scanf("%lf", &operando_1);
    printf("Digite um segundo numero: ");
    scanf("%lf", &operando_2);

    printf("Digite a operacao a ser feita sobre os numeros (+ - * / ^): ");
    char operador;
    scanf(" %c", &operador);

    double resultado;
    /*
    if (operador == '+') {
        resultado = operando_1 + operando_2;
    } else {
        if (operador == '-') {
            (...)
        }
    }
    */
    switch (operador) {
        case '+':
            resultado = operando_1 + operando_2;
            break;

        case '-':
            resultado = operando_1 - operando_2;
            break;

        case '*':
            resultado = operando_1 * operando_2;
            break;

        case '/':
            resultado = operando_1 / operando_2;
            break;

        case '^':
            resultado = pow(operando_1, operando_2);
            break;

        case '\n':
            printf("Ops, tem um <Enter> esquecido na memoria de entrada do teclado!...\n");
            return EXIT_FAILURE;

        default:
            printf("Operador invalido, nao eh possivel executar!\n");
            return EXIT_FAILURE;
    }
    printf("O resultado da operacao %c sobre os operandos eh %lf\n", operador, resultado);
    return EXIT_SUCCESS;
}