#include <stdlib.h>
#include <stdio.h>

int main() {
    int segundos_total;
    printf("Digite o numero de segundos decorridos desde a meia-noite: ");
    scanf("%d", &segundos_total);

    int horas = segundos_total / 3600;  // calcula horas cheias (com 3600 segundos)
    segundos_total %= 3600; // fica apenas com o resto para calcular os minutos

    int minutos = segundos_total / 60;  // calcula minutos cheios (com 60 segundos)
    int segundos = segundos_total % 60;

    printf("%d segundos desde a meia-noite significam a hora %02d:%02d:%02d.\n",
           segundos_total, horas, minutos, segundos);

    return EXIT_SUCCESS;
}
