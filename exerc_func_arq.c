/* Escreva um programa que grave num arquivo-texto, na forma de colunas, os
 * valores resultantes da aplicacao das funcoes seno (sin), cosseno (cos) e
 * tangente (tan) de angulos entre 0 e 90 graus.
 * Dica: eh necessario usar a biblioteca matematica (<math.h>), e os parametros
 * devem estar em radianos (use a formula: radianos = graus * PI / 180).
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
    FILE* arq = fopen("tabela.txt", "w");
    if (arq == NULL) {
        perror("Nao pude criar o arquivo");
        return EXIT_FAILURE;
    }
    // Escreve um cabecalho para o arquivo-texto, que vai identificar as colunas
    fputs("Graus;Radianos;Seno;Cosseno;Tangente\n", arq);
    double graus;
    for (graus = 0.0; graus <= 90.0; ++graus) {
        double radianos = graus * 3.14159 / 180.0;
        double s = sin(radianos);
        double c = cos(radianos);
        double t = tan(radianos);
        fprintf(arq, "%lf;%lf;%lf;%lf;%lf\n", graus, radianos, s, c, t);
    }
    fclose(arq);

    return EXIT_SUCCESS;
}
