#include <stdio.h>

// inicio
int main() {

//  declare R, C : real
    float R, C;

//  leia R
    printf("Digite R (raio): ");
    scanf("%f", &R);

//  C <- 2 * 3.1416 * R
    C = 2 * 3.1416 * R;

//  escreva C
    printf("C = %f\n", C);

    return 0;
// fim
}

