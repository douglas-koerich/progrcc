#include <stdlib.h>
#include <stdio.h>

int main() {
    float preco;
    int codigo;

    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Informe o codigo de origem: ");
    scanf("%d", &codigo);

    float total = preco; // inicia o total a pagar com o preco original

    printf("O produto procede da regiao ");
    switch (codigo) {
        case 1:
            printf("Sul\n");
            total += 12.5;     // total = total + 12.50
            break;

        case 2:
            printf("Norte\n");
            total += 35.00;
            break;

        case 3:
            printf("Leste\n");
            total += 10;
            break;

        case 4:
            printf("Oeste\n");
            total += 15;
            break;

        case 5: // NAO eh case 5, 6: e nem case 5-6:
        case 6:
            printf("Nordeste\n");
            total += 20;
            break;

        case 7: case 8: case 9:
            printf("Sudeste\n");
            break;

        default:
            if (codigo >= 10 && codigo <= 20) { // if (10 <= codigo <= 20) NAO EXISTE
                printf("Centro-oeste\n");
                total += 27;
            } else {
                if (codigo >= 21 && codigo <= 30) {
                    printf("Nordeste\n");
                    total += 18.50;
                } else {
                    printf("Codigo de origem invalido/desconhecido\n");
                    return EXIT_FAILURE;
                }
            }
    }

    printf("O total a pagar eh R$ %.2f\n", total);

    return EXIT_SUCCESS;
}