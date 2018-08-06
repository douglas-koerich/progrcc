#include <stdlib.h>
#include <stdio.h>

int main() {
    // Declaracao das variaveis
    int a, b;

    // Leitura das variaveis
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);

    // Troca de variaveis
    /*
    int aux;    // declaracao
    aux = b;    // atribuicao
    */
    int aux = b;    // inicializacao
    b = a;
    b = aux;
    // int aux = b; b = a, a = aux;    // operador virgula para separacao

    // Escrita das variaveis
    /*
    printf("O valor de a agora eh %d\n", a);
    printf("O valor de b agora eh %d\n", b);
    */
    printf("O valor de a agora eh %d e o de b eh %d\n", a, b);

    return EXIT_SUCCESS;    // constante definida em stdlib.h
}
