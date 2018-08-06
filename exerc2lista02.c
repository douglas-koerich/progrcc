#include <stdlib.h>
#include <stdio.h>

int main() {
    int dia, mes, ano;

    // Assume-se que o usuario nao digitara data invalida (32/13/-1986)
    printf("Digite a data de interesse, no formato D/M/AAAA: ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    int D = dia;
    int M;
    if (mes >= 3) {
        M = mes - 2;
        // Ano nao muda
    }
    else {
        /*
        if (mes == 1) {
            M = 11;
        }
        else {
            M = 12;
        }
        */
        M = mes + 10;
        --ano;  // Decrementa o ano (para o precedente)
    }
    int S = ano / 100;
    int A = ano % 100;

    // Vamos separar a grande formula em termos individuais pra facilitar
    // o entendimento:
    // X = TRUNCA(2,6xM-0,1)
    int X = 2.6 * M - 0.1;  // resultado da conta eh um double, atribuindo pra int ele "trunca"
    // QA = QUOCIENTE(A,4)
    int QA = A / 4;
    // QS = QUOCIENTE(S,4)
    int QS = S / 4;

    // Formula final
    int DS = (X + D + A + QA + QS - 2 * S) % 7;
    if (DS < 0) {   // Ajuste nao previsto na formula original!!!
        DS += 7;
    }
    switch (DS) {
        case 0:
            printf("O dia da semana eh DOMINGO\n");
            break;
        case 1:
            printf("O dia da semana eh SEGUNDA\n");
            break;
        case 2:
            printf("O dia da semana eh TERCA\n");
            break;
        case 3:
            printf("O dia da semana eh QUARTA\n");
            break;
        case 4:
            printf("O dia da semana eh QUINTA\n");
            break;
        case 5:
            printf("O dia da semana eh SEXTA\n");
            break;
        case 6:
            printf("O dia da semana eh SABADO\n");
            break;
    }
    return EXIT_SUCCESS;
}
