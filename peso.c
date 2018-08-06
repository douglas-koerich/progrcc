#include <stdlib.h>
#include <stdio.h>

/* Algoritmo em pseudo-codigo
inicio
    declare massa : inteiro
    declare peso : real
    leia massa
    peso <- 9.81 * massa
    escreva peso
fim
*/

int main() {
    // float massa, peso;  // se fossem do mesmo tipo
    int massa;
    // int massa = 5;   // inicializacao da variavel, criando com um valor original

    printf("O valor original da variavel 'massa' eh %d.\n", massa);

    printf("Digite a massa do objeto [kg]: ");
    scanf("%d", &massa);

    float peso;

    // peso = 9.81 * massa;     // constante do tipo 'double'
    peso = 9.81F * massa;       // constante do tipo 'float'

    // float peso = 9.81F * massa;  // inicializando com o resultado da expressao

    /*
    // Prova real
    printf("Tamanho da constante double = %d\n", sizeof(9.81));
    printf("Tamanho da constante float = %d\n", sizeof(9.81F));
    */

    printf("O peso do objeto eh %.2f N.\n", peso);

    return EXIT_SUCCESS;
}
