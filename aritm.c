#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    printf("Digite o primeiro operando: ");
    int op1;
    scanf("%d", &op1);
    printf("Agora, digite o segundo: ");
    int op2;
    scanf("%d", &op2);

    // Operacoes basicas
    int s = op1 + op2; // inicializacao com o resultado da operacao
    printf("Soma = %d\n", s);
    s = op1 - op2; // sobrescreve o valor anterior
    printf("Subtracao = %d\n", s);

    printf("Multiplicacao = %d\n", op1 * op2); // usa resultado como entrada do printf
    printf("Divisao (INTEIRA!) = %d\n", op1 / op2);
    printf("Resto da divisao = %d\n", op1 % op2);

    // Operacoes usando funcoes da biblioteca padrao da linguagem C
    int p = pow(op1, op2); // op1 elevado a op2
    float r = sqrt(op1);

    printf("op1^op2 = %d, raiz de op1 = %f\n", p, r);

    float i;
    i = 1 / (float)(op1 + op2); // () altera a precedencia padrao, com (cast)
                                // pra mudar o resultado da soma pra um float
    printf("O inverso da soma eh %f\n", i);

    return EXIT_SUCCESS;
}

