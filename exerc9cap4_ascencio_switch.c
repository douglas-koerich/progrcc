#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    time_t t = time(0); // time(0) retorna o tempo atual (em segundos desde 1/jan/1970)
    struct tm d;
    memcpy(&d, localtime(&t), sizeof(d));   // localtime() converte pra data atual

    int dia, mes, ano, hora, min;
    dia = d.tm_mday;
    mes = d.tm_mon + 1; // tm_mon numera os meses iniciando em 0 (zero)
    ano = d.tm_year - 100;  // tm_year retorna quantos anos se passaram depois de 1900

    printf("Data atual: %02d/%02d/20%02d - ", dia, mes, ano);
    switch (mes) {
        case 1:
            printf("janeiro.\n");
            break;
        case 2:
            printf("fevereiro.\n");
            break;
        case 3:
            printf("marco.\n");
            break;
        case 4:
            printf("abril.\n");
            break;
        case 5:
            printf("maio.\n");
            break;
        case 6:
            printf("junho.\n");
            break;
        case 7:
            printf("julho.\n");
            break;
        case 8:
            printf("agosto.\n");
            break;
        case 9:
            printf("setembro.\n");
            break;
        case 10:
            printf("outubro.\n");
            break;
        case 11:
            printf("novembro.\n");
            break;
        case 12:
            printf("dezembro.\n");
            break;  // opcional
    }
    hora = d.tm_hour;
    min = d.tm_min;
    printf("Hora atual: %02d:%02d.\n", hora, min);

    return EXIT_SUCCESS;
}
