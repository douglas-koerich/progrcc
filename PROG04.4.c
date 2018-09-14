#include <stdlib.h>
#include <stdio.h>

float calcula_tensao(float, float);

int main() {
    float diametro, carga, tensao;

    printf("Digite o diametro da barra cilindrica: ");
    scanf("%f", &diametro);
    printf("Agora forneca o valor da carga aplicada: ");
    scanf("%f", &carga);

    tensao = calcula_tensao(diametro, carga);

    printf("O valor da tensao eh %f\n", tensao);

    return EXIT_SUCCESS;
}

float calcula_tensao(float D, float Q) {
    int n;
    if (D > 100.0) {
        n = 2;
    } else if (D < 50.0) {
        n = 6;
    } else {
        n = 4;
    }
    float S;
    S = 4 * Q / (3.1416 * D * D) * n;
    return S;
}

