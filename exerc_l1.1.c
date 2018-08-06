#include <stdlib.h>
#include <stdio.h>

int main() {
    int total;
    printf("Digite os segundos decorridos desde a meia-noite: ");
    scanf("%d", &total);

    // Divisao INTEIRA!
    int horas = total / 3600; // sao 3600 segundos em 1 hora

    total = total % 3600;   // fica com os segundos restantes
                            // alternativa: total %= 3600;
                            //
    int minutos = total / 60;   // 60 segundos em 1 minuto

    int segundos = total % 60;  // segundos que ficaram

    printf("Tempo decorrido: %02d:%02d:%02d\n", horas, minutos, segundos);

    return EXIT_SUCCESS;
}

