#include <stdlib.h>
#include <stdio.h>

int main() {
    float preco, total;
    int origem;

    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Digite o codigo de origem: ");
    scanf("%d", &origem);

    printf("Produto veio do "); // completado pelos 'puts' abaixo
    switch (origem) {
        case 1:
            puts("Sul");
            total = preco + 12.5;
            break;
        case 2:
            puts("Norte");
            total = preco + 35;
            break;
        case 3:
            puts("Leste");
            total = preco + 10;
            break;
        case 4:
            puts("Oeste");
            total = preco + 15;
            break;
        case 5: case 6:
            puts("Nordeste");
            total = preco + 20;
            break;
        case 7:
        case 8:
        case 9:
            puts("Sudeste");
            total = preco;
            break;
        default:
            // todo o resto
            if (origem >= 10 && origem <= 20) {
                puts("Centro-oeste");
                total = preco + 27;
            } else {
                if (origem >= 21 && origem <= 30) {
                    puts("Nordeste");
                    total = preco + 18.5;
                } else {
                    puts("CAIXA-PREGO! Codigo de origem INVALIDO");
                    return EXIT_FAILURE;
                }
            }
    }
    printf("Total do produto (com frete) = R$ %.2f\n", total);

    return EXIT_SUCCESS;
}

