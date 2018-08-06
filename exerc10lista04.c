#include <stdlib.h>
#include <stdio.h>

float calcula_imposto(float, int);

int main(void) {
    float renda_liquida, imposto_a_pagar;
    int num_dependentes;

    printf("Digite a renda do contribuinte: ");
    scanf("%f", &renda_liquida);
    printf("Informe o numero de dependentes: ");
    scanf("%d", &num_dependentes);

    imposto_a_pagar = calcula_imposto(renda_liquida, num_dependentes);

    printf("Voce eh um feliz contribuinte de R$ %.2f.\n", imposto_a_pagar);

    return EXIT_SUCCESS;
}

float calcula_imposto(float renda, int dependentes) {
    float desconto = dependentes * 1600.00;
    float imposto_bruto, imposto_liquido;
    if (renda <= 20000.00) {
        imposto_bruto = 0.00;
    } else { // > 20000.00
        if (renda <= 35000.00) {
            imposto_bruto = renda * 15 / 100;
        } else { // > 35000.00
            if (renda <= 45000.00) {
                imposto_bruto = renda * 22.5 / 100;
            } else { // > 45000.00
                imposto_bruto = renda * 0.275;
            }
        }
    }
    imposto_liquido = imposto_bruto - desconto;
    if (imposto_liquido < 0.00) {
        return 0.00;
    } else {
        return imposto_liquido;
    }
}
