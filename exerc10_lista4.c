#include <stdlib.h>
#include <stdio.h>

float calcula_imposto(float, unsigned);

int main() {
    float renda;
    unsigned dependentes;

    printf("Digite a renda liquida do contribuinte: ");
    scanf("%f", &renda);
    printf("Quantos dependentes ele(a) possui? ");
    scanf("%u", &dependentes);

    float imposto = calcula_imposto(renda, dependentes);

    printf("O imposto a pagar eh R$ %.2f.\n", imposto);

    return EXIT_SUCCESS;
}

float calcula_imposto(float renda, unsigned deps) {
    float imp;
    if (renda <= 20000.0) {
        imp = 0;
    } else {
        if (renda <= 35000.0) {
            imp = renda * 15 / 100;
        } else {
            if (renda <= 45000.0) {
                imp = renda * 0.225;
            } else {
                imp = renda * .275;
            }
        }
    }
    imp -= deps * 1600.0;
    if (imp < 0.0) {
        imp = 0.0;
    }
    return imp;
}

