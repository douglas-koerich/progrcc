#include <stdlib.h>
#include <stdio.h>

int main() {
    float x1, y1; // coordenadas do primeiro ponto da reta
    float x2, y2; // coordenadas do segundo ponto

    float y; // ordenada do ponto em questao (dado)
    float x; // abscissa do ponto em questao (para calcular)

    printf("Digite a coordenada X do primeiro ponto: ");
    scanf("%f", &x1);
    printf("Digite a coordenada Y do primeiro ponto: ");
    scanf("%f", &y1);

    printf("Agora, digite a coordenada X do segundo ponto: ");
    scanf("%f", &x2);
    printf("Digite a coordenada Y do segundo ponto: ");
    scanf("%f", &y2);

    printf("Finalmente, digite a coordenada Y do ponto desejado: ");
    scanf("%f", &y);

    x = (y - y1) * (x2 - x1) / (y2 - y1) + x1; // isolando x na formula do enunciado

    printf("A coordenada X do ponto em questao eh %f\n", x);    
    
    return EXIT_SUCCESS;
}