#include <stdlib.h>
#include <stdio.h>

int main() {
    int codigo;
    float preco, frete, total;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    printf("Agora digite o seu preco: ");
    scanf("%f", &preco);

    switch (codigo) {
        case 1:
            printf("Produto vindo do Sul\n");
            frete = 12.50;
            break;  // impede que se continue executando o codigo
                    // do case seguinte

        case 2:
            printf("Produto vindo do Norte\n");
            frete = 35.00;
            break;

        case 3:
            printf("Produto vindo do Leste\n");
            frete = 10.00;
            break;

        case 4:
            printf("Produto vindo do Oeste\n");
            frete = 15.00;
            break;

        case 5:
        case 6:
            // Mesmo bloco comum ao case 5 e ao case 6
            printf("Produto vindo do Nordeste\n");
            frete = 20.00;
            break;

        case 7:
        case 8:
        case 9:
            printf("Produto vindo do Sudeste\n");
            frete = 0.00;
            break;

        default:
            // Todos os outros valores diferentes de 1 a 9
            if (codigo >= 10 && codigo <= 20) {
                printf("Produto vindo do Centro-Oeste\n");
                frete = 27.00;
            } else {
                if (codigo >= 21 && codigo <= 30) {
                    printf("Produto vindo do Nordeste\n");
                    frete = 18.50;
                } else {
                    // Nenhum dos codigos/intervalos anteriores
                    printf("Erro! Codigo invalido!\n");
                    return EXIT_FAILURE; // termina o programa AQUI!
                }
            }
    }
    total = preco + frete;
    printf("Total a pagar: %.2f\n", total);

    return EXIT_SUCCESS;
}

