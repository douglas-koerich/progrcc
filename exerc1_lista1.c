#include <stdlib.h>
#include <stdio.h>

int main() {
    // Variavel para armazenar o numero total de segundos desde a meia-noite
    // (entrada do usuario)
    int segundos_total;

    // Variaveis de saida
    int horas, minutos, segundos;

    printf("Digite o numero de segundos passados desde a meia-noite: ");
    scanf("%d", &segundos_total);

    horas = segundos_total / 3600; // calcula o numero de horas "cheias" no total
    int resto = segundos_total % 3600; // os segundos que nao completaram uma hora
    minutos = resto / 60; // calcula o numero de minutos "cheios" no resto
    segundos = resto % 60; // os segundos que sobraram

    printf("O total corresponde a %02d:%02d:%02d.\n", horas, minutos, segundos);

    return EXIT_SUCCESS;
}

