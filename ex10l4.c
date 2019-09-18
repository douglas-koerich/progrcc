#include <stdlib.h>
#include <stdio.h>

float calcula_imposto(float, unsigned);

int main(void) {
    float r, imposto;
    unsigned dep;

    printf("Digite a renda do(a) contribuinte: ");
    scanf("%f", &r);
    printf("Informe o numero de dependentes: ");
    scanf("%u", &dep);

    imposto = calcula_imposto(r, dep);

    printf("Imposto a pagar: R$ %.2f\n", imposto);

    return EXIT_SUCCESS;
}

float calcula_imposto(float renda, unsigned dependentes) {
    float aliquota;
    if (renda <= 20000.0) {
        aliquota = 0;
    } else { // > 20000.0 (>= 20000.01)
        if (renda <= 35000.0) {
            aliquota = 15;
        } else {
            if (renda <= 45000.0) {
                aliquota = 22.5;
            } else {
                aliquota = 27.5;
            }
        }
    }
    float pagar = renda * aliquota / 100; // calculo percentual
    float desconto = dependentes * 1600.0;
    pagar -= desconto;
    if (pagar < 0) {
        pagar = 0; // o Estado nao reembolsa imposto... X-(
    }
    return pagar;
}

