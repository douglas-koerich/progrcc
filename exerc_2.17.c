#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double R;
    printf("Digite o raio da esfera: ");
    scanf("%lf", &R);

    const double PI = 3.1415927;

    double C = 2 * PI * R;
    printf("Comprimento (C) = %lf\n", C);

    double A;
    A = PI * R * R;
    printf("Area (A) = %lf\n", A);

    double V;
    V = 3.0 / 4 * PI * pow(R, 3);
    printf("Volume (V) = %lf\n", V); 

    return EXIT_SUCCESS;
}

