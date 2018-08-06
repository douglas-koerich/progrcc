#include <stdlib.h>
#include <stdio.h>

int main() {
    int variavel;           // Declaracao de uma variavel do tipo inteiro

    // Entrada & saida de um valor inteiro
    printf("Digite um numero inteiro: ");
    scanf("%d", &variavel);
    printf("Obrigado, voce digitou o valor %d\n", variavel);

    // Alguns compiladores permitem a declaracao da variavel no meio do codigo
    // (eh claro, antes de qualquer uso que se pretenda da mesma)
    float qualquer = -1.5F; // Declaracao com inicializacao de valor na variavel
    printf("O valor de 'qualquer' eh %f\n", qualquer);
    printf("Digite um novo valor para 'qualquer': ");
    scanf("%f", &qualquer);
    printf("O NOVO valor de 'qualquer' eh %f\n", qualquer);

    double d1, d2;          // Duas variaveis nao inicializadas
    printf("d2 = %lf\n", d2);
    printf("Digite um valor para d1: ");
    scanf("%lf", &d1);
    printf("O valor digitado foi %lf\n", d1);

    char c1 = 'A', c2 = 'a';
    /*
    char ca = A, cb = a;    // Errado, o compilador vai tentar copiar das variaveis A e a
                            // (que NAO existem!!!)
    */
    printf("c1 = %c\n", c1);
    printf("Digite um simbolo para armazenar em c2: ");
    scanf(" %c", &c2);  // ponha um espaco antes do %c para limpar os espacos e saltos de linha
    printf("O caracter escolhido foi: %c\n", c2);

    int v1 = 10, v2 = 10;   // Diferente de fazer: int v1, v2 = 10; (inicializa soh v2)
    printf("v1 = %d, v2 = %d\n", v1, v2);
    v1 = v2 = 20;   // A atribuicao (diferente da inicializacao) pode ser feita assim
    printf("v1 = %d, v2 = %d\n", v1, v2);
    v1 = 30;
    printf("v1 = %d, v2 = %d\n", v1, v2);

    double c = 300000; /* m/s = velocidade da luz no vacuo */
    printf("c = %lf\n", c);
    printf("c = %e\n", c);
}
