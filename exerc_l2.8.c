#include <stdlib.h>
#include <stdio.h>

int main() {
    float preco;
    int codigo;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    printf("Qual o preco do produto? ");
    scanf("%f", &preco);

    float frete;

    /*
    if (codigo == 1) {
        printf("Originario do Sul.\n");
        frete = 12.50;
    } else {
        if (codigo == 2) {
            printf("Originario do Norte.\n");
            frete = 35.00;
        } else {
            if (codigo == 3) {
                printf("Originario do Leste.\n");
                frete = 10.00;
            } else {
                if (codigo == 4) {
                    printf("Originario do Oeste.\n");
                    frete = 15.00;
                } else {
                    if (codigo == 5 || codigo == 6) {
                        printf("Originario do Nordeste.\n");
                        frete = 20.00;
                    } else {
                        if (codigo == 7 || codigo == 8 || codigo == 9) {
                            printf("Originario do Sudeste.\n");
                            frete = 0.00;
                        } else {
                            if (codigo >= 10 && codigo <= 20) {
                                printf("Originario do Centro-Oeste.\n");
                                frete = 27.00;
                            } else {
                                if (codigo >= 21 && codigo <= 30) {
                                    printf("Originario do Nordeste.\n");
                                    frete = 18.50;
                                } else {
                                    printf("CODIGO INVALIDO!\n");
                                    return EXIT_FAILURE;
                                }
                                printf("Precisei chegar ao fim da tabela na comparacao, ufa!...\n");
                            }
                        }
                    }
                }
            }
        }
    }
    */
    switch (codigo) {
        case 1:
            printf("Originario do Sul.\n");
            frete = 12.50;
            break;

        case 2: 
            printf("Originario do Norte.\n");
            frete = 35.00;
            break;

        case 3:
            printf("Originario do Leste.\n");
            frete = 10.00;
            break;

        case 4:
            printf("Originario do Oeste.\n");
            frete = 15.00;
            break;

        case 5: case 6:
            printf("Originario do Nordeste.\n");
            frete = 20.00;
            break;

        case 7:
        case 8:
        case 9:
            printf("Originario do Sudeste.\n");
            frete = 0.00;
            break;

        default:
            // Para nao fazer case 10: case 11: ... etc. etc.
            if (codigo >= 10 && codigo <= 20) {
                printf("Originario do Centro-Oeste.\n");
                frete = 27.00;
            } else {
                if (codigo >= 21 && codigo <= 30) {
                    printf("Originario do Nordeste.\n");
                    frete = 18.50;
                } else {
                    printf("CODIGO INVALIDO!\n");
                    return EXIT_FAILURE;
                }
            }
    }
    float total = preco + frete;
    printf("O valor total eh R$ %.2f.\n", total);

    return EXIT_SUCCESS;
}

