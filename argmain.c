#include <stdlib.h>
#include <stdio.h>

int main(int num_params, char* vetor_params[]) { // char** vetor_params
    // Se parametros sao esperados, inicia verificando o numero deles
    if (num_params < 4) {
        puts("Numero insuficiente de parametros na linha de comando");
        printf("Use: %s <operando1> <operando2> <+|-|x|/>\n", vetor_params[0]);
        return EXIT_FAILURE;
    }
    // Este programa fara a operacao aritmetica indicada na linha de comando
    char operacao = vetor_params[3][0]; // primeiro caractere [0] da string na posicao [3] (4o. argumento) do vetor
    float operando_1 = atof(vetor_params[1]);   // converte string pra float
    float operando_2;
    sscanf(vetor_params[2], "%f", &operando_2);

    float resultado;
    switch (operacao) {
        case '+': resultado = operando_1 + operando_2; break;
        case '-': resultado = operando_1 - operando_2; break;
        case 'x': resultado = operando_1 * operando_2; break;
        case '/':
            if (operando_2 != 0.0) {
                resultado = operando_1 / operando_2;
            } else {
                puts("Nao pode dividir por zero!");
                return EXIT_FAILURE;
            }
            break;
        default: // o usuario indicou um operador invalido
            puts("Operacao invalida");
            return EXIT_FAILURE;
    }
    printf("%f\n", resultado);
    return EXIT_SUCCESS;
}

