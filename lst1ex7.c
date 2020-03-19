#include <stdlib.h>
#include <stdio.h>

int main() {
    float total, felipe;
    int carlos, andre; // essas variaveis armazenam apenas inteiros

    printf("Valor total da conta (R$)? ");
    scanf("%f", &total);

    // A sequencia de atribuicoes (=) da linha abaixo indica que
    // tanto a variavel 'carlos' quanto a variavel 'andre' recebem
    // o mesmo valor
    carlos = andre = total / 3; // a conversao de float (vindo da divisao)
                                // para int elimina os centavos
    
    felipe = total - carlos - andre;

    printf("Divisao da conta:\n");

    // Nas linhas a seguir, as variaveis 'carlos' e 'andre' sao
    // "vistas" como float's pelo compilador (uso do conceito de "cast")
    printf("Carlos = R$ %.2f\n", (float) carlos);
    printf("Andre  = R$ %.2f\n", (float) andre);
    printf("Felipe = R$ %.2f\n", felipe);

    return EXIT_SUCCESS;
}
