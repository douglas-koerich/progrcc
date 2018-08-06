#include <stdlib.h>
#include <stdio.h>

// inicio
int main() {
    // declare preco, total : real
    float preco, total;

    // declare codigo : inteiro
    int codigo;

    // leia preco, codigo
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Digite o codigo de origem: ");
    scanf("%d", &codigo);

    // escolha codigo
    switch (codigo) {
        // caso 1
        case 1:
            // escreva "Sul"
            printf("Sul\n");

            // total <- preco + 12.50
            total = preco + 12.50;
            break;  // separa o case atual do proximo

        // caso 2
        case 2:
            // escreva "Norte"
            printf("Norte\n");

            // total <- preco + 35.00
            total = preco + 35.00;
            break;

        // caso 3
        case 3:
            // escreva "Leste"
            printf("Leste\n");

            // total <- preco + 10.00
            total = preco + 10.00;
            break;

        // caso 4
        case 4:
            // escreva "Oeste"
            printf("Oeste\n");

            // total <- preco + 15.00
            total = preco + 15.00;
            break;

        // caso 5, 6
        case 5: case 6:
            // escreva "Nordeste"
            printf("Nordeste\n");

            // total <- preco + 20.00
            total = preco + 20.00;
            break;

        // caso 7, 8, 9
        case 7: case 8: case 9:
            // escreva "Sudeste"
            printf("Sudeste\n");

            // total <- preco
            total = preco;
            break;
        /*
        // caso 10 .. 20
        case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        case 18: case 19: case 20:
            // escreva "Centro-oeste"
            printf("Centro-oeste\n");

            // total <- preco + 27.00
            total = preco + 27.00;
            break;

        // caso 21 .. 30
        case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28:
        case 29: case 30:
            // escreva "Nordeste"
            printf("Nordeste\n");

            // total <- preco + 18.50
            total = preco + 18.50;
            break;
        */
        // caso contrario   ; outros valores
        default:
            // Artificio do programa para nao ter cases multiplos como exemplificado
            // acima; um tratamento por 'if' eh sempre melhor no caso de **faixa** de valores
            if (codigo >= 10 && codigo <= 20) {
                // escreva "Centro-oeste"
                printf("Centro-oeste\n");

                // total <- preco + 27.00
                total = preco + 27.00;
            }
            else if (codigo >= 21 && codigo <= 30) {
                // escreva "Nordeste"
                printf("Nordeste\n");

                // total <- preco + 18.50
                total = preco + 18.50;
            }
            else {
                // escreva "Origem INVALIDA"
                printf("Origem INVALIDA\n");

                // total <- 0
                total = 0.0;
            }
            // A ULTIMA (nao necessariamente default) NAO precisa ter break;
    // fim-escolha
    }
    // escreva total
    printf("O total do produto eh $%.2f\n", total);

    return EXIT_SUCCESS;
// fim
}
