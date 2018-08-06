#include <stdlib.h>
#include <stdio.h>

int main() {
    int mes, dias;
    printf("Digite o mes de interesse: (1=Jan, 2=Fev, ..., 12=Dez): ");
    scanf("%d", &mes);


    /* Jeito #1: usando "escada if-else"
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
        dias = 31;
    }
    else {  // Todos os outros meses...
        if (mes == 2) { // desconsiderando bissextos...
            dias = 28;
        }
        else {
            if (mes < 1 || mes > 12) {
                printf("Mes invalido!");
                return EXIT_FAILURE;    // sai do programa imediamente, com indicacao de erro
            }
            else {
                dias = 30;
            }
        }
    }
    */
    switch (mes) {
        case 2:
            dias = 28;
            break;

        case 1:
        case 3:     // em linhas separadas...
        case 5:
        case 7:
        case 8: case 10: case 12:   // ... ou na mesma linha
            dias = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            dias = 30;
            break;

        default:    // todo o resto (outros possiveis - mas nesse caso invalidos - valores)
            printf("Mes invalido!");
            return EXIT_FAILURE;
    }
    printf("O numero de dias desse mes eh %d.\n", dias);
    return EXIT_SUCCESS;
}
