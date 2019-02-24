#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14

int main() {
    printf("Meu primeiro programa em C\n");

    float area;
    area = PI * pow(5, 2);
    printf("A area do circulo de raio 5 eh %f\n", area);

    return EXIT_SUCCESS;
}

