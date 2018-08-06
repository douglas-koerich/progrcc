#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float Vf, Vi, i;
    int N;

    printf("Valor inicial? "); scanf("%f", &Vi);
    printf("Numero de periodos (meses)? "); scanf("%d", &N);
    printf("Taxa de juros (0%% a 100%%)? "); scanf("%f", &i);
    // i = i / 100;
    i /= 100;

    /*
    float inter1 = pow(1+i, N);
    float inter2 = Vi * inter1;
    Vf = inter2;
    */
    Vf = Vi * pow(1+i, N);

    printf("Rendimento = $%.2f, valor final = $%.2f\n", Vf-Vi, Vf);

	return EXIT_SUCCESS;
}
