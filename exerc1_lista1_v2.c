#include <stdlib.h>
#include <stdio.h>

int main() {
    int horas, minutos, segundos;

    printf("Digite o numero de segundos passados desde a meia-noite: ");
    scanf("%d", &segundos);

    horas = segundos / 3600;
    segundos = segundos % 3600; // reuso da variavel com novo valor
    minutos = segundos / 60;
    segundos %= 60; // os segundos que sobraram

    printf("O total corresponde a %02d:%02d:%02d.\n", horas, minutos, segundos);

    return EXIT_SUCCESS;
}

