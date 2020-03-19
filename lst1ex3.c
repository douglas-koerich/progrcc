#include <stdlib.h>
#include <stdio.h>

/* Note que o enunciado do exercicio pede que se calcule o valor
 * de x, dado o correspondente valor de y. Isso significa que a
 * formula indicada deve ser trabalhada a fim de "isolar" a variavel
 * x na mesma ;-)
 */

int main() {
    // Coordenadas do primeiro ponto informado
    float x1, y1;
    printf("Digite a coordenada X do primeiro ponto: ");
    scanf("%f", &x1);
    printf("Digite tambem a coordenada Y do primeiro ponto: ");
    scanf("%f", &y1);

    // Coordenadas do segundo ponto
    float x2, y2;
    printf("Agora, digite a coordenada X do segundo ponto: ");
    scanf("%f", &x2);
    printf("Por ultimo, a coordenada Y do segundo ponto: ");
    scanf("%f", &y2);

    // Coordenada Y do ponto que se deseja encontrar
    float y;
    printf("Digite a coordenada Y do ponto procurado: ");
    scanf("%f", &y);

    // Calculo de X com a formula jah modificada para isolar essa variavel
    float x = (y - y1) * (x2 - x1) / (y2 - y1) + x1;

    printf("O ponto procurado estah na coordenada X = %.3f\n", x);

    return EXIT_SUCCESS;
}

