#include <stdlib.h>
#include <stdio.h>

int main() {
    // Variaveis de entrada
    // Ponto 1 (x1, y1)
    float x1, y1;
    // Ponto 2 (x2, y2)
    float x2, y2;
    // Ordenada (y) do ponto a descobrir
    float y;

    // Leitura das variaveis de entrada
    printf("Digite as coordenadas x,y do 1o. ponto: ");
    scanf("%f,%f", &x1, &y1);
    printf("Digite as coordenadas x,y do 2o. ponto: ");
    scanf("%f,%f", &x2, &y2);
    printf("Agora digite a ordenada y do ponto a descobrir: ");
    scanf("%f", &y);

    // Calculo exige o isolamento da variavel x na formula
    float x;
    x = (y - y1)*(x2 - x1)/(y2 - y1) + x1; // soma passa diminuindo, divisao passa multiplicando, etc.

    // Escrita/impressao da variavel de saida
    printf("A abscissa do ponto eh %f\n", x);

    return EXIT_SUCCESS;
}

