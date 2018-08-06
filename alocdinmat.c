#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAMANHO 10000
// Declarar a matriz como variavel global eh indesejavel
// do ponto de vista de seguranca/engenharia de software
// int matriz[TAMANHO][TAMANHO];

int main(void) {
    srand((unsigned) time(NULL));
    // Declarar a matriz como variavel local seria o ideal
    // mas a pilha (area da memoria onde as locais sao criadas)
    // nao tem enorme capacidade como requerido por essa matriz
    // int matriz[TAMANHO][TAMANHO];
    int l, c;

    // Para essa situacao, pedimos ao SISTEMA OPERACIONAL (dono da heap)
    // para reservar uma area de memoria para nossa "variavel", como
    // o compilador teria feito para variaveis de verdade nas outras regioes
    int* matriz = malloc(TAMANHO*TAMANHO*sizeof(int));

    for (l = 0; l < TAMANHO; ++l) {
        for (c = 0; c < TAMANHO; ++c) {
            // matriz[l][c] = rand();
            *(matriz + l*TAMANHO + c) = rand();
        }
    }

    unsigned num_elementos = 0, cont_mult_7 = 0;
    for (l = 0; l < TAMANHO; ++l) {
        for (c = 0; c < TAMANHO; ++c) {
            // if (matriz[l][c] % 7 == 0) {
            if (*(matriz + l*TAMANHO + c) % 7 == 0) {
                ++cont_mult_7;
            }
            ++num_elementos;
        }
    }

    printf("O numero de multiplos de 7 gerados foi %u em %u.\n", cont_mult_7, num_elementos);

    free(matriz);   // ### CUIDADO! ### Tem que ser o mesmo valor numerico de endereco
                    // que foi recebido pela chamada a malloc()

    return EXIT_SUCCESS;
}
