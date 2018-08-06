#include <stdlib.h>
#include <stdio.h>

int main() {
    float preco, total;
    int codigo;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    printf("Valor do produto (R$): ");
    scanf("%f", &preco);
    total = preco; // inicia total com o preco
    switch (codigo) {
        case 1:
            printf("Sul\n");
            total += 12.50;
            break;
        case 2:
            printf("Norte\n");
            total += 35.00;
            break;
        case 3:
            printf("Leste\n");
            total += 10.00;
            break;
        case 4:
            printf("Oeste\n");
            total += 15.00;
            break;
        case 5:
        case 6:
            printf("Nordeste\n");
            total += 20.00;
            break;
        case 7: case 8: case 9:
            printf("Sudeste\n");
            break;
        default:
            if (codigo >= 10 && codigo <= 20) {
                printf("Centro-oeste\n");
                total += 27.00;
            } else {
                if (codigo >= 21 && codigo <= 30) {
                    printf("Nordeste\n");
                    total += 18.50;
                }
                else {
                    printf("CODIGO INVALIDO\n");
                    return EXIT_FAILURE;
                }
            }
    }
    printf("Valor total com frete: R$ %.2f\n", total);
    return EXIT_SUCCESS;
}

