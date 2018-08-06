#include <stdlib.h>
#include <stdio.h>

int main() {
    // Variaveis de entrada: dois pontos e a coordenada y
    float x1, y1, x2, y2, y;

    // Variavel de saida: coordenada x
    float x;

    printf("Digite o primeiro ponto na forma X,Y: ");
    scanf("%f,%f", &x1, &y1);
    printf("Digite o segundo ponto na forma X,Y: ");
    scanf("%f,%f", &x2, &y2);

    printf("Digite a coordenada Y do ponto a saber: ");
    scanf("%f", &y);

    // Formula modificada (isolando o x)
    x = (y-y1)*(x2-x1)/(y2-y1) + x1;

    printf("A coordenada X respectiva vale %.3f\n", x);
    
    return EXIT_SUCCESS;
}
