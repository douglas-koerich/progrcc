#include <stdlib.h>
#include <stdio.h>

int main() {
    int idade;
    printf("Digite a idade do(a) nadador(a): ");
    scanf("%d", &idade);
    printf("A categoria dele(a) eh ");

    /*
    // 1a. forma: "escada" if-else
    if (idade >= 5 && idade <= 7) {
        printf("Infantil A.\n");
    } else {
        if (idade >= 8 && idade <= 10) {
            printf("Infantil B.\n");
        } else {
            if (idade >= 11 && idade <= 13) {
                printf("Juvenil A.\n");
            } else {
                if (idade >= 14 && idade <= 17) {
                    printf("Juvenil B.\n");
                } else {
                    if (idade >= 18) {
                        printf("Adulto.\n");
                    } else {
                        printf("(IDADE INVALIDA).\n");
                    }
                }
            }
        }
    }
    */

    // 2a. forma: multipla-escolha
    switch (idade) {
        case 5: case 6: case 7:
            printf("Infantil A.\n");
            break;
        case 8: case 9: case 10:
            printf("Infantil B.\n");
            break;
        case 11: case 12: case 13:
            printf("Juvenil A.\n");
            break;
        case 14: case 15: case 16: case 17:
            printf("Juvenil B.\n");
            break;
        default:    // todos os outros valores de idade
            if (idade >= 18) {
                printf("Adulto.\n");
            } else {
                printf("(IDADE INVALIDA).\n");
            }
    }

    return EXIT_SUCCESS;
}
