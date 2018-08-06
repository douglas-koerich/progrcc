#include <stdlib.h>
#include <stdio.h>

/* Converter NNNN segundos para HH:MM:SS eh o processo de DECOMPOR
   o total de segundos em blocos de "horas cheias", tomando o resto
   e decompondo em "minutos cheios" e usando o restante como os
   segundos remanescentes */

int main() {
    int segundos_total, horas, minutos, segundos;

    printf("Digite o total de segundos desde a meia-noite: ");
    scanf("%d", &segundos_total);

    horas = segundos_total / (60 * 60); // em uma hora ha 60*60 = 3600 segundos
    /*
    segundos_total = segundos_total % 3600; // desconta o que ficou nas horas
    */
    segundos_total %= 3600; // operador composto ("aglutinado")

    minutos = segundos_total / 60;
    segundos = segundos_total % 60;

    printf("Esse montante de segundos equivale a %02d:%02d:%02d.\n", horas,
        minutos, segundos);

    return EXIT_SUCCESS;
}
