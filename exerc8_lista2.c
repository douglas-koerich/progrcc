#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned codigo;
    float preco;

    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Codigo do produto: ");
    scanf("%u", &codigo);

    float total = preco;
    printf("Origem: ");
    switch (codigo) {
        case 1:
            total += 12.50;
            printf("Sul\n");
            break;

        case 2:
            total += 35.00;
            printf("Norte\n");
            break;

        case 3:
            total += 10.00;
            printf("Leste\n");
            break;

        case 4:
            total += 15.00;
            printf("Oeste\n");
            break;

        case 5: case 6:
            total += 20.00;
            printf("Nordeste\n");
            break;

        case 7:
        case 8:
        case 9:
            // Nao ha frete
            printf("Sudeste\n");
            break;

        /* Ao inves de individualizar os valores das faixas mais extensas...
        case 10: case 11: case 12: case 13: case 14:
        case 15: case 16: case 17: case 18: case 19: case 20:
            total += 27.00;
            printf("Centro-Oeste\n");
            break;
        */
        default:
            if (codigo >= 10 && codigo <= 20) {
                total += 27.00;
                printf("Centro-Oeste\n");
            } else if (codigo >= 21 && codigo <= 30) {
                total += 18.50;
                printf("Nordeste\n");
            } else {
                printf("Codigo INVALIDO!\n");
                return EXIT_FAILURE;
            }
    }
    printf("Preco total (com frete): $%.2f\n", total);

    return EXIT_SUCCESS;
}
