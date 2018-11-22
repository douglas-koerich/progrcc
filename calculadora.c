#include <stdlib.h>
#include <stdio.h>

// int main(int argc, char* argv[]) {
int main(int num_params, char* params[]) {
    double a, b, r;
    /*
    printf("Digite o primeiro numero (a): ");
    scanf("%lf", &a);
    printf("Agora, o segundo numero (b): ");
    scanf("%lf", &b);
    */
    if (num_params < 4) { // nome do programa conta no numero
        puts("Numero insuficiente de parametros");

        // O nome do programa pelo qual foi chamado na linha de
        // comando eh o primeiro elemento do vetor de argumentos
        printf("Use: %s <num1> <operador> <num2>\n", params[0]);

        return EXIT_FAILURE;
    }
    // Precisa converter os numeros que vem na forma de strings
    // para o tipo double (necessario para executar a operacao)
    a = atof(params[1]);
    b = atof(params[3]);

    char op;
    /*
    printf("Escolha a operacao a ser executada (+ - * /): ");
    scanf(" %c", &op);
    */

    // Como a string eh um vetor de caracteres, basta pegar o
    // primeiro caracter da mesma como o simbolo do operador
    op = params[2][0]; // indice 0 da string que estah no indice 2 do vetor de strings

    switch (op) {
        case '+': r = a + b;
                  break;

        case '-': r = a - b;
                  break;

        // Como *, / e \ sao usados como caracteres especiais em
        // comandos Linux, entao escolhemos x e d como operadores
        case 'x': r = a * b;
                  break;

        case 'd':
            if (b != 0.0) {
                r = a / b;
            } else {
                puts("Operando invalido (nulo)!");
                return EXIT_FAILURE;
            }
            break;

        default:
            puts("Operador invalido!");
            return EXIT_FAILURE;
    }
    /*
    printf("O resultado eh %lf.\n", r);
    */
    printf("%lf\n", r);

    return EXIT_SUCCESS;
}

