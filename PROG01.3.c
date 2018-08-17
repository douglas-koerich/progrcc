#include <stdlib.h>
#include <stdio.h>

int main() {
    float x1, y1, /* primeiro par */ x2, y2, // segundo par
          y, // ordenada do ponto em questao
          x; // abscissa que se quer calcular

    printf("Digite as coordenadas do primeiro ponto x,y: ");
    scanf("%f,%f", &x1, &y1); // o usuario DEVERA usar a virgula entre os valores
                              // OBS. metodo de entrada NAO recomendavel
    printf("Digite x do segundo ponto: ");
    scanf("%f", &x2);
    printf("Digite y do segundo ponto: ");
    scanf("%f", &y2);
    printf("Digite a ordenada (y) do ponto que quer encontrar: ");
    scanf("%f", &y);

    // Isolando x na formula do enunciado ficamos com a seguinte expressao
    //      y-y1
    // x = ------(x2-x1) + x1
    //      y2-y1
    x = (y - y1)/(y2 - y1)*(x2 - x1) + x1;

    printf("A abscissa (x) do ponto eh %f.\n", x);

    return EXIT_SUCCESS;
}

