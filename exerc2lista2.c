#include <stdlib.h>
#include <stdio.h>

int main() {
    int dia, mes, ano;
    printf("Digite a data no formato D/M/AAAA: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    int M, D, A, S, DS;
    D = dia;
    if (mes == 1 || mes == 2) {
        /*
        ano = ano - 1; // ano precedente
        // ou ano -= 1;
        */
        --ano;
        M = mes + 10;
    } else {
        M = mes - 2;
    }
    S = ano / 100; // dois primeiros digitos do ano
    A = ano % 100; // dois ultimos digitos

    int truncado = 2.6 * M - 0.1; // truncagem feita pela dispensa da parte fracionaria
                                  // ao copiar um resultado real para um 'int'
    int q1 = A / 4;
    int q2 = S / 4;

    DS = (truncado + D + A + q1 + q2 - 2 * S) % 7; // parenteses para fazer + e - antes do %

    switch (DS) {
        case 0:
            printf("Domingo\n");
            break;
        case 1:
            printf("Segunda\n");
            break;
        case 2:
            printf("Terca\n");
            break;
        case 3:
            printf("Quarta\n");
            break;
        case 4:
            printf("Quinta\n");
            break;
        case 5:
            printf("Sexta\n");
            break;
        case 6:
            printf("Sabado\n");
            break;
    }

    return EXIT_SUCCESS;
}

