#include <stdlib.h>
#include <stdio.h>

int main() {
    int codigo;
    float preco, frete, total;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    printf("Agora digite o seu preco: ");
    scanf("%f", &preco);

    if (codigo == 1) {
        printf("Produto vindo do Sul\n");
        frete = 12.50;
    } else {
        // Todos os codigos diferentes de 1
        if (codigo == 2) {
            printf("Produto vindo do Norte\n");
            frete = 35.00;
        } else {
            // Todos os codigos diferentes de 2
            // (e de 1 tambem, pois estah no mesmo else mais externo)
            if (codigo == 3) {
                printf("Produto vindo do Leste\n");
                frete = 10.00;
            } else {
                if (codigo == 4) {
                    printf("Produto vindo do Oeste\n");
                    frete = 15.00;
                } else {
                    if (codigo == 5 || codigo == 6) {
                        printf("Produto vindo do Nordeste\n");
                        frete = 20.00;
                    } else {
                        if (codigo == 7 || codigo == 8 || codigo == 9) {
                            printf("Produto vindo do Sudeste\n");
                            frete = 0.00;
                        } else {
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
                    }
                }
            }
        }
    }
    /* Versao sem escada, possivel porque cada 'else' tem apenas
     * um if-else (interno) como comando associado...
    if (codigo == 1) {
        printf("Produto vindo do Sul\n");
        frete = 12.50;
    } else if (codigo == 2) {
        printf("Produto vindo do Norte\n");
        frete = 35.00;
    } else if (codigo == 3) {
        printf("Produto vindo do Leste\n");
        frete = 10.00;
    } else if (codigo == 4) {
        printf("Produto vindo do Oeste\n");
        frete = 15.00;
    } else if (codigo == 5 || codigo == 6) {
        printf("Produto vindo do Nordeste\n");
        frete = 20.00;
    } else if (codigo == 7 || codigo == 8 || codigo == 9) {
        printf("Produto vindo do Sudeste\n");
        frete = 0.00;
    } else if (codigo >= 10 && codigo <= 20) {
        printf("Produto vindo do Centro-Oeste\n");
        frete = 27.00;
    } else if (codigo >= 21 && codigo <= 30) {
        printf("Produto vindo do Nordeste\n");
        frete = 18.50;
    } else {
        // Nenhum dos codigos/intervalos anteriores
        printf("Erro! Codigo invalido!\n");
        return EXIT_FAILURE; // termina o programa AQUI!
    }
    */
    total = preco + frete;
    printf("Total a pagar: %.2f\n", total);

    return EXIT_SUCCESS;
}

