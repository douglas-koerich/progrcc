#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>  // tolower
#include "mygets.h"

#define MAX_FRASE   140
#define NUM_LETRAS  26

int main(void) {
    char tweet[MAX_FRASE+1];

    printf("Digite uma frase: ");
    Gets(tweet, sizeof(tweet)); // como eh um vetor de bytes, o tamanho em bytes
                                // (obtido por sizeof) eh o mesmo tamanho do vetor
                                // (em numero de elementos) - MAX_FRASE+1
    
    unsigned contador = 0;

    // 1o. jeito de resolver:
    char c;
    for (c = 'a'; c <= 'z'; ++c) {  // ++c incrementa o codigo ASCII -> proxima letra!
        int i = 0;
        while (tweet[i] != '\0') {  // enquanto nao encontra a marca de fim da string no vetor...
            if (tolower(tweet[i]) == c) { // pra comparar com 'a', 'b', 'c' e nao 'A', 'B', 'C'...
                ++contador;
                break;  // nao preciso continuar, ja encontrei uma ocorrencia dessa letra pra contar
                        // NOTE QUE O break TERMINA O while, NAO O LACO for!!!
            }
            ++i;
        }
    }

    // 2o. jeito, usando um vetor de contadores
    //   a   b   c   d   e     <-- letra
    // +---+---+---+---+---+...
    // | 0 | 0 | 0 | 0 | 0 |...<-- contador de cada letra
    // +---+---+---+---+---+...

    unsigned contadores[NUM_LETRAS] = {};   // valores inicializados com 0
    int i = 0;
    while (tweet[i] != '\0') {  // pra todos os caracteres anteriores ao terminador nulo
        if (isalpha(tweet[i])) {    // eh uma letra?
            int indice = tolower(tweet[i]) - 'a';   // se for 'b', fica 'b'-'a' (cods. ASCII) = 1
            ++contadores[indice];   // incrementa o contador correspondente
        }
        ++i;
    }
    for (i=contador=0; i<NUM_LETRAS; ++i) {  // conta o numero de elementos do vetor que sao maiores que zero
        if (contadores[i] > 0) {    // (foi encontrada a letra no laco anterior)
            ++contador;
        }
    }

    printf("Foram encontradas %u letras diferentes.\n", contador);
    return EXIT_SUCCESS;
}

