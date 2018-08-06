#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Digite o salario do funcionario: ");
    float salario;
    scanf("%f", &salario);

    printf("Digite o tempo de casa dele(a), em anos: ");
    int anos;
    scanf("%d", &anos);

    float bonus;
    if (salario <= 400.0) {
        bonus = salario * 15 / 100; // Que bom! salario sendo float garante que a divisao eh real!
    }
    else if (salario > 1000.0) {
        bonus = salario * 0.05;
    }
    else {  // este 'else' eh do 'if (salario > 1000.0)', nao do 'if (salario <= 400.0)'
        bonus = salario * .12;
    }

    float extra = (anos >= 3)? salario * 10 / 100 : 0.0;
    /* float extra;
    if (anos >= 3) {
        extra = salario * 10 / 100;
    }
    else {
        extra = 0.0;
    } */
    printf("O salario final do funcionario, com bonus eh R$ %.2f.\n", salario + bonus + extra);

    /* Ou, numa forma mais "rustica"...
    printf("O salario final do funcionario, com bonus eh R$ %.2f.\n",
           salario + bonus + ((anos >= 3)? salario * 10 / 100 : 0.0));
    */
    return EXIT_SUCCESS;
}
