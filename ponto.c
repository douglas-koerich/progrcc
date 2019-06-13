#include <stdlib.h>
#include <stdio.h>
#include <math.h> // pow e sqrt
#include "ponto.h"

int main(void) {
    Ponto A, B;

    printf("Digite as coordenadas do ponto A, na forma x,y: ");
    scanf("%f,%f", &A.x, &A.y);
    
    printf("Digite as coordenadas do ponto B, na forma x,y: ");
    scanf("%f,%f", &B.x, &B.y);

    //float d = calcula_distancia(A, B); // passando uma COPIA dos pontos
    float d = calcula_distancia(&A, &B); // passando os ENDERECOS dos pontos

    printf("A distancia entre os pontos no plano eh %f.\n", d);
    
    return EXIT_SUCCESS;
}

float calcula_distancia(const Ponto *a, const Ponto *b) {
    float v1 = pow((*a).x - (*b).x, 2); // usa o operador * para chegar nas estruturas
    float v2 = pow(a->y - b->y, 2); // usa o operador -> para alcancar os campos usando os ponteiros (sem *!!!)
    float dist = sqrt(v1 + v2);
    return dist;
}

