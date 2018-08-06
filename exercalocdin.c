/* Elabore um programa que leia uma serie de n notas, e calcule quantas sao 10% acima
 * da media e quantas sao 10% abaixo. O numero de notas eh informado pelo usuario antes da
 * serie.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int num_params, char* lista_params[]) {
    if (num_params < 2) {   // n nao foi informado na linha de comando?
        puts("Numero insuficiente de parametros");
        printf("Use: %s <qtde-notas>\n", lista_params[0]);
        return EXIT_FAILURE;
    }
    // O valor de n vem na forma de string, precisa converter
    // para inteiro a fim de ser usado na dimensao do vetor
    int n = atoi(lista_params[1]);  // converte de Ascii para (to) Inteiro

    float* vetor_notas = malloc(sizeof(float) * n);

    // Preenche o vetor com notas aleatorias
    int i;
    float soma = 0.0;
    srand((unsigned) time(NULL));
    puts("Vetor de notas:");
    for (i = 0; i < n; ++i) {
        *(vetor_notas + i) = rand() % 11 + (rand() % 100 / 100.0);
        if (*(vetor_notas + i) > 10.0) {
            *(vetor_notas + i) = 10.0;
        }
        printf("%.2f ", *(vetor_notas + i));
        soma += *(vetor_notas + i);
    }
    putchar('\n');
    float media = soma / n;

    unsigned abaixo10pc = 0, acima10pc = 0;
    for (i = 0; i < n; ++i) {
        if (*(vetor_notas + i) > media * 1.1) {
            ++acima10pc;
        }
        if (*(vetor_notas + i) < media * 0.9) {
            ++abaixo10pc;
        }
    }
    printf("Os numeros de notas acima e abaixo do desvio de 10%% da media (%.2f) sao, respectivamente, %u e %u.\n",
           media, acima10pc, abaixo10pc);

    free(vetor_notas);

    return EXIT_SUCCESS;
} 
