#include <stdlib.h>
#include <stdio.h>

float calculaImposto(int dependentes, float renda);

int main(void) {
    float renda, imposto;
    int dependentes;

    printf("Digite a sua renda (R$): ");
    scanf("%f", &renda);
    printf("Digite o numero de dependentes: ");
    scanf("%d", &dependentes);

    imposto = calculaImposto(dependentes, renda);
    printf("O imposto a pagar eh de R$ %.2f.\n", imposto);
    return EXIT_SUCCESS;
}

float calculaImposto(int dependentes, float renda) {
    float desconto = dependentes * 1600;
    float aliquota;
    if (renda <= 20000.0) {
        aliquota = 0.0;
    }
    else if (renda > 20000.0 && renda <= 35000.0) {
        aliquota = renda * 15 / 100;
    }
    else if (renda > 35000.0 && renda <= 45000.0) {
        aliquota = renda * 22.5 / 100;
    }
    else {
        aliquota = renda * 0.275;   // ja normalizado 27.5/100
    }
    float imposto = aliquota - desconto;
    if (imposto < 0.0) {    // isento com dependentes?
        imposto = 0.0;      // nao pode dar um "credito" de imposto
    }
    return imposto;
}

