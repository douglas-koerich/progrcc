#include <stdlib.h>
#include <stdio.h>

float calcula_tensao(float, double);

int main() {
    float D;
    double Q;
    printf("Digite o diametro da barra: ");
    scanf("%f", &D);
    printf("Digite a carga: ");
    scanf("%lf", &Q);

    float S = calcula_tensao(D, Q);
    printf("A tensao vale %f\n", S);

    return EXIT_SUCCESS;
}

float calcula_tensao(float x, double y) {
    if (x == 0.0) {
        return 0.0;
    }
    float tensao;
    int n;
    if (x > 100.0) {
        n = 2;
    } else {
        if (x < 50.0) {
            n = 6;
        } else {
            n = 4;
        }
    }
    tensao = 4 * y * n / (3.1416 * x * x);
    return tensao;
}

