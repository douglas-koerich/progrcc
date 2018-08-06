#include <stdlib.h>
#include <stdio.h>

int main() {
    float conta; // tipo adequado para moeda
    printf("Digite o valor total da conta: ");
    scanf("%f", &conta);

    int carlos, andre;
    float felipe;

    carlos = andre = conta / 3; // a copia do quociente para inteiro vai truncar
    /* andre = conta / 3;
     * carlos = andre;
     */
    felipe = conta - carlos - andre;

    printf("Carlos e Andre pagarao cada um %.2f\n", (float) carlos); // uso de "cast" em C
    printf("Felipe pagara %.2f\n", felipe);

    return EXIT_SUCCESS;
}

