#include <stdlib.h>
#include <stdio.h>

int main() {
    // Variaveis de entrada: preco e codigo de origem
    float preco;
    int codigo;

    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    printf("Informe a origem do produto digitando o codigo numerico: ");
    scanf("%d", &codigo);

    float frete;
    
    printf("A procedencia do produto eh ");
    /*
    // 1a. solucao: usando a "escada" if-else
    if (codigo == 1) {
        printf("Sul\n");
        frete = 12.50; // ou 12.5
    } else {
        if (codigo == 2) {
            printf("Norte\n");
            frete = 35.00; // ou 35.0, ou ainda 35 apenas
        } else {
            if (codigo == 3) {
                printf("Leste\n");
                frete = 10.00;
            } else {
                if (codigo == 4) {
                    printf("Oeste\n");
                    frete = 15.00;
                } else {
                    if (codigo == 5 || codigo == 6) {
                        printf("Nordeste\n");
                        frete = 20.00;
                    } else {
                        if (codigo == 7 || codigo == 8 || codigo == 9) {
                            printf("Sudeste\n");
                            frete = 0.00;
                        } else {
                            if (codigo >= 10 && codigo <= 20) {
                                printf("Centro-Oeste\n");
                                frete = 27.00;
                            } else {
                                if (codigo >= 21 && codigo <= 30) {
                                    printf("Nordeste\n");
                                    frete = 18.50;
                                } else {
                                    printf("CODIGO INVALIDO!\n");

                                    // Nao faz sentido continuar, encerra o
                                    // programa aqui indicando erro
                                    return EXIT_FAILURE;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    */

    // 2a. solucao: escolha-caso
    switch (codigo) { // decisao eh baseada no VALOR da variavel
        case 1: // nao eh necessario chaves {} a nao ser que se crie uma
                // variavel temporaria dentro deste 'case'
            printf("Sul\n");
            frete = 12.50; // ou 12.5
            break; // "fim" do case

        case 2:
            printf("Norte\n");
            frete = 35.00; // ou 35.0, ou ainda 35 apenas
            break;

        case 3:
            printf("Leste\n");
            frete = 10.00;
            break;

        case 4:
            printf("Oeste\n");
            frete = 15.00;
            break;

        case 5: case 6: // na mesma linha...
            printf("Nordeste\n");
            frete = 20.00;
            break;

        case 7: // ... ou em linhas separadas
        case 8:
        case 9:
            printf("Sudeste\n");
            frete = 0.00;
            break;

        default:
            if (codigo >= 10 && codigo <= 20) {
                printf("Centro-Oeste\n");
                frete = 27.00;
            } else {
                if (codigo >= 21 && codigo <= 30) {
                    printf("Nordeste\n");
                    frete = 18.50;
                } else {
                    printf("CODIGO INVALIDO!\n");

                    // Nao faz sentido continuar, encerra o
                    // programa aqui indicando erro
                    return EXIT_FAILURE;
                }
            }
            // A ultima clausula do switch (nao necessariamente a default,
            // se ela vier no meio de cases) nao precisa de break
    }

    float total = preco + frete;
    printf("O valor total do produto eh R$ %.2f\n", total);

    return EXIT_SUCCESS;
}

