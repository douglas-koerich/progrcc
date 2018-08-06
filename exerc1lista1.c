#include <stdio.h>

int main() {
    // Variavel de entrada (numero total de segundos desde a meia-noite)
    unsigned segundos;

    // Variaveis de saida (horas, minutos e segundos decorridos desde entao)
    unsigned horas, minutos, segundos2;

    // 1o. passo do algoritmo: ler o numero total de segundos
    printf("Ola, quantos segundos se passaram desde a meia-noite? ");
    scanf("%u", &segundos); // %u -> unsigned... nao esquecer o & (!!!)

    // 2o. passo: transformar em HH:MM:SS
    horas = segundos / 3600;          // horas cheias
    unsigned resto = segundos % 3600; // segundos da "hora quebrada" restante
    minutos = resto / 60;             // minutos cheios
    segundos2 = resto % 60;           // segundos do "minuto quebrado" restante

    // 3o. passo: imprimir o resultado
    printf("%u segundos equivalem a %02u:%02u:%02u\n",
           segundos, horas, minutos, segundos2);

    return 0;
}

