#include <stdlib.h>
#include <stdio.h>

float formula(float, float);

int main() {
    float tensao, diametro, carga;
    
    printf("Digite o diametro da barra cilindrica: ");
    scanf("%f", &diametro);
    printf("Digite a carga imposta a essa barra: ");
    scanf("%f", &carga);

    tensao = formula(diametro, carga);

    printf("A tensao a que a barra estah submetida eh %f.\n", tensao);

    return EXIT_SUCCESS;
}

float formula(float D, float Q) {
    int n;
    if (D > 100) {
        n = 2;
    } else if (D < 50) {
        n = 6;
    } else {
        n = 4;
    }
    float S;
    S = 4 * Q * n / (3.1416 * D * D);
    return S;
}

