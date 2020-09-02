#include <stdlib.h>
#include <stdio.h>

int main() {
    // Variaveis de entrada do programa
    float preco_fabrica, perc_lucro, perc_impostos;

    printf("Digite o preco de fabrica do veiculo (R$): ");
    scanf("%f", &preco_fabrica); // nao esquecer o & antes da variavel!!

    printf("Percentual de lucro do distribuidor (%%): ");
    scanf("%f", &perc_lucro);
    printf("Percentual de impostos (%%): ");
    scanf("%f", &perc_impostos);

    float valor_lucro = preco_fabrica * perc_lucro / 100;
    float valor_impostos = preco_fabrica * perc_impostos / 100;
    float preco_final = preco_fabrica + valor_lucro + valor_impostos;

    printf("a) Valor do lucro do distribuidor: R$ %.2f\n", valor_lucro);
    printf("b) Valor dos impostos: R$ %.2f\n", valor_impostos);
    printf("c) Preco final para o consumidor: R$ %.2f\n", preco_final);

    return EXIT_SUCCESS;
}