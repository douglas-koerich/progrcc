#include <stdio.h>

int main() {
    int dia, mes, ano;

    printf("Digite o dia (1-31): ");
    scanf("%d", &dia);
    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);
    printf("Digite o ano (4 digitos AAAA): ");
    scanf("%d", &ano);

    int D = dia;
    int M;
    if (mes == 1 || mes == 2) { // janeiro ou fevereiro?
        M = mes + 10;           // janeiro=11, fevereiro=12
        ano = ano - 1;
    }
    else {
        M = mes - 2;
    }
    // Certifico-me que o ano tem 4 digitos, se tiver apenas 2 vai ser
    // a partir de 2000
    if (ano < 100) {
        if (ano > 15) {
            ano += 1900;
        }
        else {
            ano += 2000;
        }
    }
    int A = ano % 100;  // dois ultimos digitos (resto da divisao por 100)
    int S = ano / 100;  // dois primeiros digitos (quociente dessa divisao)

    // RESTO(TRUNCA(2,6×M–0,1)+D+A+QUOCIENTE(A,4)+QUOCIENTE(S,4)–2×S),7)
    // X = TRUNCA(2,6×M–0,1)
    // Y = QUOCIENTE(A,4)
    // Z = QUOCIENTE(S,4)
    // W = X+D+A+Y+Z-2×S
    // DS = RESTO(W,7)
    
    // "Truncar" significa ignorar a parte fracionaria de um valor real
    // Fazemos isso simplesmente copiando o resultado real para uma variavel
    // inteira em C
    int X = 2.6 * M - 0.1;
    int Y = A / 4;
    int Z = S / 4;
    int W = X+D+A+Y+Z-2*S;
    int DS = W % 7;

    /*
    // printf("Voce nasceu num(a) %d\n", DS);
    if (DS == 0) {
        printf("Voce nasceu num domingo!\n");
    }
    else {
        if (DS == 1) {
            printf("Voce nasceu numa segunda-feira!\n");
        }
        else {
            if (DS == 2) {
                printf("Voce nasceu numa terca-feira!\n");
            }
            else {
                if (DS == 3) {
                    printf("Voce nasceu numa quarta-feira!\n");
                }
                else {
                    if (DS == 4) {
                        printf("Voce nasceu numa quinta-feira!\n");
                    }
                    else {
                        if (DS == 5) {
                            printf("Voce nasceu numa sexta-feira!\n");
                        }
                        else {  // soh existe um outro valor possivel...
                            printf("Voce nasceu num sabado!\n");
                        }
                    }
                }
            }
        }
    }
    */
    /* ... OU ...
    if (DS == 0)
        printf("Voce nasceu num domingo!\n");
    else if (DS == 1)
        printf("Voce nasceu numa segunda-feira!\n");
    else if (DS == 2)
        printf("Voce nasceu numa terca-feira!\n");
    else if (DS == 3)
        printf("Voce nasceu numa quarta-feira!\n");
    else if (DS == 4)
        printf("Voce nasceu numa quinta-feira!\n");
    else if (DS == 5)
        printf("Voce nasceu numa sexta-feira!\n");
    else // soh existe um outro valor possivel...
        printf("Voce nasceu num sabado!\n");
    */

    switch (DS) { // "Qual valor estah armazenado em DS?"
        case 0:
            printf("Voce nasceu num domingo!\n");
            break;
        case 1:
            printf("Voce nasceu numa segunda-feira!\n");
            break;
        case 2:
            printf("Voce nasceu numa terca-feira!\n");
            break;
        case 3:
            printf("Voce nasceu numa quarta-feira!\n");
            break;
        case 4:
            printf("Voce nasceu numa quinta-feira!\n");
            break;
        case 5:
            printf("Voce nasceu numa sexta-feira!\n");
            break;
        default: // todos os demais (nesse caso, soh o valor 6)...
            printf("Voce nasceu num sabado!\n");
    }
    return 0;
}

