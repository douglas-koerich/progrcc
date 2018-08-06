#include <stdlib.h>
#include <stdio.h>

float calculaImposto(float, unsigned);

int main(void) {
    float r, i;
    unsigned d;
    printf("Digite a renda liquida (R$): ");
    scanf("%f", &r);
    printf("Digite o numero de dependentes: ");
    scanf("%u", &d);
    i = calculaImposto(r, d);
    printf("O imposto a pagar eh R$ %.2f.\n", i);
    return EXIT_SUCCESS;
}

float calculaImposto(float renda, unsigned dependentes) {
    if (renda <= 20000.0) {
        return 0.0;
    }
    // else {} - nao eh preciso fazer um else porque o return dentro do if sairia
    // da funcao de qualquer forma
    float aliquota;
    if (renda > 20000.0 && renda <= 35000.0) {  // eh dispensavel comparar com 20000.0
                                                // porque o teste anterior ja excluiu a
                                                // possibilidade de ter um valor menor aqui
        aliquota = 0.15;    // usa coeficiente no lugar de percentagem
    } else if (renda <= 45000.0) {
        aliquota = 0.225;
    } else {
        aliquota = 0.275;
    }
    float imposto = renda * aliquota;
    imposto -= dependentes * 1600.0;    // tira de imposto o desconto por dependentes
    if (imposto < 0.0) {    // se o numero de dependentes fez o imposto ficar negativo...
        imposto = 0.0;
    }
    return imposto;
}
