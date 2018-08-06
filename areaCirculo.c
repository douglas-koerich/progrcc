#include <stdio.h>

float calculaArea(float);

int main() {
    float r;
    do {
        printf("Digite o raio (0 para terminar): ");
        scanf("%f", &r);

        printf("A area do circulo correspondente eh %f\n", calculaArea(r));
    } while (r != 0.0);

    return 0;
}

float calculaArea(float raio) {
    if (raio < 0.0) {
        return 0.0;
    }
    float area;
    const float PI = 3.14159265354;
    area = PI * raio * raio;
    return area;
}
