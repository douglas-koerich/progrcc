#include <stdlib.h>
#include <stdio.h>

int main() {
    float preco_fabrica, perc_lucro, imposto,
          valor_lucro, valor_imposto, soma_final;

    printf("Digite o preco de fabrica do carro: ");
    scanf("%f", &preco_fabrica);
    printf("Digite o percentual de lucro do distribuidor (%%): ");
    scanf("%f", &perc_lucro);
    printf("Digite a aliquota de imposto sobre o preco (%%): ");
    scanf("%f", &imposto);

    valor_lucro = preco_fabrica * perc_lucro / 100;
    valor_imposto = preco_fabrica * imposto / 100;
    soma_final = preco_fabrica + valor_lucro + valor_imposto;

    printf("Os valores finais sao: lucro = %.2f, imposto = %.2f, total = %.2f\n",
           valor_lucro, valor_imposto, soma_final);

    return EXIT_SUCCESS;
}

