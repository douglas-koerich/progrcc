/* Escreva um programa em C que leia as temperaturas maximas de
 * cada dia da semana e calcule a media dessas maximas. */

#include <stdlib.h>
#include <stdio.h>

int main() {
    puts("Digite as temperaturas maximas da semana: ");
    int dia = 1;
    float temperatura, acumulado = 0.0;

    for (dia = 1, acumulado = 0.0; dia <= 7; ++dia /*, acumulado += temperatura*/) {
        printf("Dia %d: ", dia);
        scanf("%f", &temperatura);
        acumulado += temperatura;
    }

    /* Versao alternativa, pouco usual:
     * for (;;) { // baseia-se na inicializacao das variaveis acima
     *     printf("Dia %d: ", dia);
     *     scanf("%f", &temperatura);
     *     acumulado += temperatura;
     *     if (++dia > 7) { // incremento eh parte do proprio laco (como no while)
     *         break; // interrupcao do laco neste ponto (nao executa mais nada)
     *     }
     * }
     */

    float media = acumulado / 7;
    printf("A media das maximas na semana eh %.2f\n", media);

    return EXIT_SUCCESS;
}

