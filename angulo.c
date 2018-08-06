/*
"Escreva um algoritmo em linguagem C que, chamado por um programa com
 um valor de angulo dado em graus, converta-o para as unidades grados
 e radianos, devolvendo-as ao programa para impressao.
 Lembrando:
    1 grau = 0,0174533 radianos
    1 grau = 1,1111111 grados."
*/

#include <stdlib.h>
#include <stdio.h>

float converte_radianos(float);
float converte_grados(float);
void converte_ambos(float, float*, float*);

int main(void) {
    float graus, radianos, grados;
    printf("Digite o valor do angulo, em graus: ");
    scanf("%f", &graus);
    /*
    radianos = converte_radianos(graus);
    grados = converte_grados(graus);
    */
    converte_ambos(graus, &radianos, &grados);
    
    printf("Radianos = %.3f, grados = %.3f.\n", radianos, grados);
    
    return EXIT_SUCCESS;
}

float converte_radianos(float g) {
    float r;
    r = g * 0.0174533;
    return r;
}

float converte_grados(float g) {
    float G;
    G = g * 1.1111111;
    return G;
}

void converte_ambos(float g, float* rad, float* grad) {
    float r;
    r = g * 0.0174533;
    *rad = r;   // ou *rad = g * 0.0174533;
    float G;
    G = g * 1.1111111;
    *grad = G;  // ou *grad = g * 1.1111111;
}
