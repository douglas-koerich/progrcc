#include <stdio.h>

int main() {
    float preco, total;
    int codigo;

    printf("Digite o preco do produto (R$): "); scanf("%f", &preco);
    printf("Digite o codigo de origem: "); scanf("%d", &codigo);

    printf("Procedencia: ");
    switch (codigo) {
        case 1:
            printf("Sul\n");
            total = preco + 12.50;
            break;

        case 2:
            printf("Norte\n");
            total = preco + 35.00;
            break;

        case 3:
            printf("Leste\n");
            total = preco + 10.00;
            break;

        case 4:
            printf("Oeste\n");
            total = preco + 15.00;
            break;

        case 5: case 6:
            printf("Nordeste\n");
            total = preco + 20.00;
            break;

        case 7:
        case 8:
        case 9:
            printf("Sudeste\n");
            total = preco;  // Gratis!
            break;

        // case 10: case 11: case 12: case 13: ... (ah, cansei!)
        default: // (todos os demais)
            if (codigo >= 10 && codigo <= 20) {
                printf("Centro-oeste\n");
                total = preco + 27.00;
            }
            else if (codigo >= 21 && codigo <= 30) {
                printf("Nordeste\n");
                total = preco + 18.50;
            }
            else {
                printf("### INVALIDO ###\n");
                total = 0;
            }
    }
    printf("Total a pagar: R$ %.2f\n", total);
    return 0;
}
