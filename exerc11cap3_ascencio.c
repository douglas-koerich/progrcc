#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    unsigned num;   // numero inteiro e positivo
    unsigned quad, cubo;
    float r2, r3;   // raizes provavelmente serao reais (com partes fracionarias)

    printf("Digite o numero: ");
    scanf("%u", &num);

    // quad = num * num;
    quad = pow(num, 2);

    cubo = pow(num, 3);

    r2 = sqrt(num);

    r3 = pow(num, 1.0/3);   // se usar 1/3 vai elevar a 0 (zero)!

    printf("O quadrado de %u eh %u.\n", num, quad);
    printf("O seu cubo eh %u.\n", cubo);
    printf("A raiz quadrada vale %f.\n", r2);
    printf("E a raiz cubica de %u eh %f.\n", num, r3);

    return EXIT_SUCCESS;
}
