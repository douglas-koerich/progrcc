#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    printf("Esta eh uma calculadora TOSCA que pede\n");
    printf("os numeros e depois a operacao a ser feita\n");

    float operando_1, operando_2;
    printf("Digite o primeiro operando: ");
    scanf("%f", &operando_1);
    printf("Agora, digite o segundo: ");
    scanf("%f", &operando_2);

    printf("Digite:\n");
    printf("S: soma\n");
    printf("s: subtracao\n");
    printf("M,m: multiplicacao\n");
    printf("D,d: divisao\n");
    printf("P,p: potenciacao\n");

    char operacao;
    scanf(" %c", &operacao); // nao esqueca o ' ' antes do %c para "limpar"
                             // os 'scanf's' anteriores

    float resultado;
    switch (operacao) { // nao ha comparacao aqui no switch!
        case 'S':
            resultado = operando_1 + operando_2;
            break;

        case 's':
            resultado = operando_1 - operando_2;
            break;

        case 'm':   // duas condicoes para a mesma operacao
        case 'M':
            resultado = operando_1 * operando_2;
            break;

        case 'd': case 'D': // podem estar numa mesma linha
            resultado = operando_1 / operando_2;
            break;

        case 'p': case 'P':
            resultado = pow(operando_1, operando_2);
            break;

        default:
            printf("Operacao INVALIDA!\n");
            return EXIT_FAILURE; // sai do programa neste ponto
    }
    printf("Resultado: %f\n", resultado);
    return EXIT_SUCCESS;
}

