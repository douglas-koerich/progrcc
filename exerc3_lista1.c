#include <stdlib.h>
#include <stdio.h>

int main() {
    // Ponto 1
    float x1, y1;

    // Ponto 2
    float x2, y2;

    // Coordenada y do ponto em questao
    float y;

    // Coordenada x a ser calculada
    float x;

    printf("Digite a abscissa (x) do 1o. ponto: ");
    scanf("%f", &x1);
    printf("Digite a ordenada (y) do 1o. ponto: ");
    scanf("%f", &y1);

    printf("Digite o 2o. ponto na forma x,y: ");
    scanf("%f,%f", &x2, &y2); // usuario **DEVERAH** digitar valores
                              // SEPARADOS por uma virgula

    printf("Digite a ordenada (y) do ponto a calcular: ");
    scanf("%f", &y);

    // Isolando _x_ na formula do enunciado
    // (DUVIDAS sobre o isolamento: consulte a Profa. Maria Eugenia)
    x = (y - y1) * (x2 - x1) / (y2 - y1) + x1;

    printf("A abscissa do ponto vale %f.\n", x);

    return EXIT_SUCCESS;
}

