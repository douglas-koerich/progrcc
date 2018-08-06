#include <stdlib.h>
#include <stdio.h>

int main() {
    float total, felipe;
    int carlos, andre;

    printf("Digite o total da conta: ");
    scanf("%f", &total);

    carlos = andre = total / 3; // vai armazenar nas variaveis apenas a parte inteira

    felipe = total - carlos - andre;

    printf("Valor de cada um: Carlos e Andre=$%d.00, Felipe=$%.2f\n", carlos, felipe);

    return EXIT_SUCCESS;
}
