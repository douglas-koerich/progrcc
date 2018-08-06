/* inicio
        declare P, m : real
        leia m
        P <- 9.81 * m
        escreva P
   fim */

#include <stdlib.h>
#include <stdio.h>

int main() {
    /*
    float P;
    float m;
    */
    float P, m; // essa DECLARACAO das variaveis deve acontecer ANTES do seu primeiro uso no programa
    float g = 9.81; // essa declaracao inclui tambem uma INICIALIZACAO da variavel (um valor inicial)
    printf("Digite a massa do corpo [kg]: ");
    scanf("%f", &m);    // nao esquecer o & ("e-comercial") antes da variavel no scanf!!!
    // P = 9.81 * m;   // atribuicao de valor a uma variavel eh com o sinal de igual (=)
    P = m * g;
    printf("Peso = %f N\n", P);

    return EXIT_SUCCESS;
}
