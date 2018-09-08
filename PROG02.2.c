#include <stdlib.h>
#include <stdio.h>

int main() {
    // Variaveis do programa
    int D, M, A, S, DS;

    // Entrada de dados
    printf("Digite o dia do mes: ");
    scanf("%d", &D);
    printf("Digite o numero do mes (1:Jan, 2:Fev, ...): ");
    scanf("%d", &M);
    printf("Digite o ano (NNNN): ");
    scanf("%d", &A);

    // Processamento dos dados de entrada
    if (M <= 2) {
        M += 10;    // ajusta Jan/Fev...
        --A;        // ... para o ano anterior (precedente)
    } else {
        M -= 2;
    }
    S = A / 100;    // dois primeiros digitos do ano
    A %= 100;       // dois ultimos digitos do ano

    // Formula do algoritmo (repare o uso de cast para truncar)
    DS = ((int)(2.6*M-0.1) + D + A + (A/4) + (S/4) - 2 * S) % 7;

    // Saida do programa
    printf("A data informada ocorreu num(a) ");
    switch (DS) {
        case 0:
            printf("domingo\n");
            break;

        case 1:
            printf("segunda-feira\n");
            break;

        case 2:
            printf("terca-feira\n");
            break;

        case 3:
            printf("quarta-feira\n");
            break;

        case 4:
            printf("quinta-feira\n");
            break;

        case 5:
            printf("sexta-feira\n");
            break;

        case 6:
            printf("sabado\n");
            break;

        default:
            printf("ERRO (DS negativo)!\n");
    }
    return EXIT_SUCCESS;
}

