#include <stdlib.h>
#include <stdio.h>

int main() {
    float sal, aumento, novosal;
    int perc;

    printf("Digite o salario atual: ");
    scanf("%f", &sal);
    printf("Digite o aumento percentual (%%): ");
    scanf("%d", &perc);

    aumento = sal * perc/100;   // se fizer sal*(perc/100) nao funciona!

    printf("Aumento (R$): %.2f\n", aumento); // imprime centavos

    novosal = sal + aumento;

    printf("Novo salario (R$): %.2f\n", novosal);

    return EXIT_SUCCESS;
}
