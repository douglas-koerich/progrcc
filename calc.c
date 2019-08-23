#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    printf("Digite um primeiro numero: ");
    double num1;
    scanf("%lf", &num1);
    printf("Digite um segundo numero: ");
    double num2;
    scanf("%lf", &num2);

    puts("Selecione a operacao desejada:");
    puts("+ : Soma dos numeros");
    puts("- : Subtracao do primeiro pelo segundo");
    puts("x : Multiplicacao dos numeros");
    puts("\\ : Divisao do primeiro pelo segundo");
    puts("^ : Potenciacao (primeiro elevado ao segundo)");
    puts("v : Radiciacao (raiz 'segundesima' X-) do primeiro)");
    printf("OPCAO? ");

    char oper;
    scanf(" %c", &oper); // note o uso do espaco no " %c" (limpa <Enter>)

    double res;

    /*
    if (oper == '+') {
        res = num1 + num2;
    } else {
        if (oper == '-') {
            res = num1 - num2;
        ...
    */
    switch (oper) { // inspeciona o valor da variavel 'oper'
        // Alternativas
        case '+':
            res = num1 + num2;
            break;

        case '-':
            res = num1 - num2;
            break;

        case 'x': case '*': // cada valor no seu proprio 'case'
            res = num1 * num2;
            break;

        case '\\':
        case '/':
            res = num1 / num2;
            break;

        case '^':
            res = pow(num1, num2);
            break;

        case 'v':
            res = pow(num1, 1/num2);
            break;

        default: // nenhuma das outras
            puts("Operacao INVALIDA");
            return EXIT_FAILURE; // programa sai aqui mesmo!
    }
    printf("Resultado da operacao = %lf\n", res);

    return EXIT_SUCCESS;
}
