#include <stdlib.h>
#include <stdio.h>
#include <math.h> // para uso de pow() e sqrt()

int main() {
    int A, B, C; // poderiam (talvez ateh deveriam!) ser float's
    
    printf("Digite o coeficiente de x^2 (A): ");
    scanf("%d", &A);
    printf("Digite o coeficiente de x (B): ");
    scanf("%d", &B);
    printf("Digite o termo independente (C): ");
    scanf("%d", &C);

    int delta = pow(B, 2) - 4 * A * C;

    if (delta < 0) {
        puts("Nao ha raizes reais (sao complexas)");
    } else {
        if (A == 0) {
            puts("A equacao eh do 1o. grau");
            printf("A raiz da equacao eh %f\n", -C / (float) B);
            // (note o cast acima para forcar uma divisao REAL, e nao inteira)
        } else {
            float r1 = (-B + sqrt(delta)) / (2 * A); // note os parenteses!!!
            if (delta == 0) {
                puts("As raizes sao iguais");
                printf("Seus valores sao %f\n", r1);
            } else {
                float r2; // esta variavel SOH EXISTE DENTRO DO else!
                r2 = (-B - sqrt(delta)) / (2 * A);
                printf("As raizes sao %f e %f\n", r1, r2);
            }
        }
    }
    return EXIT_SUCCESS;
}

