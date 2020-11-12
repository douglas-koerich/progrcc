/* Escreva um programa que recebe como entrada dois pontos de uma reta – dois
pares (x, y) – e um terceiro ponto para o qual o programa verifica se pertence a reta
formada pelos dois primeiros. */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "ponto.h"

bool testa_na_reta(const struct point*, const struct point*, const struct point*);

int main(void) {
    // 2 variaveis do mesmo tipo-estrutura/registro
    struct point p1;
    Point p2 = { 0, 0 }; // inicia como a origem do plano cartesiano

    // Exemplos extras de inicializacao
    Point extra = { 1.5, 4.7 };
    Point extra1 = { 1.5 }; // y = 0;
    Point extra2 = { .y = 1.5 }; // x = 0;

    // Endereco para uma "variavel" do tipo alocada dinamicamente
    struct point* p3 = malloc(sizeof(struct point)); // Point* p3 = malloc(sizeof(Point)); 

    // Leituras
    puts("Digite as coordenadas do primeiro ponto pertencente a reta:");
    printf("X? "); scanf("%lf", &p1.x);
    printf("Y? "); scanf("%lf", &p1.y);

    puts("Digite as coordenadas do segundo ponto da reta:");
    printf("X? "); scanf("%lf", &p2.x);
    printf("Y? "); scanf("%lf", &p2.y);

    puts("Informe as coordenadas do terceiro ponto (pertencente ou nao?):");
    printf("X? "); scanf("%lf", &p3->x);
    printf("Y? "); scanf("%lf", &p3->y);

    // Verificacao: calcula o y esperado para que o terceiro ponto pertenca a mesma reta
    // dos dois primeiros
    if (testa_na_reta(&p1, &p2, p3)) {
        printf("O ponto {%lf, %lf} pertence ah reta!\n", p3->x, p3->y);
    } else {
        printf("O ponto {%lf, %lf} NAO pertence ah reta!\n", p3->x, p3->y);
    }

    free(p3); // Nao esquecer a liberacao da memoria alocada

    return EXIT_SUCCESS;
}

bool testa_na_reta(const struct point* pr1, const struct point* pr2, const struct point* p) {
    double y = (pr2->y - pr1->y) / (pr2->x - pr1->x) * (p->x - pr1->x) + pr1->y;
    return y == p->y;
}
