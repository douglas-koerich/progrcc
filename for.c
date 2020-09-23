#include <stdlib.h>
#include <stdio.h>

int main() {
    int temp, dia, soma_dia, leitura;
    float media_sem, media_dia, soma_sem;

    /*
    dia = 1;
    soma = 0;
    while (dia <= 7) {
        printf("(%d) Digite a temperatura: ", dia);
        scanf("%d", &temp);

        soma += temp; // soma = soma + temp 

        ++dia;  // operador de incremento (soma 1)
    }
    */
    for (dia = 1, soma_sem = 0; dia <= 7; ++dia) {
        for (leitura = 1, soma_dia = 0; leitura <= 3; ++leitura) {
            printf("(%d:%d) Digite a temperatura: ", dia, leitura);
            scanf("%d", &temp);
            if (temp < -40 || temp > 50) {
                printf("Leitura invalida, ignorada!\n");
                /*
                soma_dia = 0;
                break;  // interrompe o laco imediatamente interior continuando pela
                        // linha de codigo seguinte (media_dia = soma_dia...)
                */
                continue;
            }
            soma_dia += temp; 
        }
        media_dia = soma_dia / 3.0;
        printf("A media do %do. dia foi %.1f\n", dia, media_dia);

        soma_sem += media_dia;
    }

    media_sem = soma_sem / 7.0; // efetua uma divisao real

    printf("A media semanal eh %.1f\n", media_sem);

    return EXIT_SUCCESS;
}