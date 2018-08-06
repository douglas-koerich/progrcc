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
    if (mes == 1) {
        printf("janeiro.\n");
    }
    if (mes == 2) {
        printf("fevereiro.\n");
    }
    if (mes == 3) {
        printf("marco.\n");
    }
    if (mes == 4) {
        printf("abril.\n");
    }
    if (mes == 5) {
        printf("maio.\n");
    }
    if (mes == 6) {
        printf("junho.\n");
    }
    if (mes == 7) {
        printf("julho.\n");
    }
    if (mes == 8) {
        printf("agosto.\n");
    }
    if (mes == 9) {
        printf("setembro.\n");
    }
    if (mes == 10) {
        printf("outubro.\n");
    }
    if (mes == 11) {
        printf("novembro.\n");
    }
    if (mes == 12) {
        printf("dezembro.\n");
    }
    hora = d.tm_hour;
    min = d.tm_min;
    printf("Hora atual: %02d:%02d.\n", hora, min);

    return EXIT_SUCCESS;
}
