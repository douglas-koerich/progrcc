/* Escreva um programa em linguagem C que leia um conjunto de
 * respostas de um teste com 20 questoes e 5 alternativas cada
 * (letras a, b, c, d ou e) e, com base num gabarito pre-definido
 * pela inicializacao da variavel correspondente, calcule e
 * mostre a nota obtida, sendo que cada questao vale 0,5 ponto. */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NUM_QUESTOES 20

int main(void) {
    char gabarito[NUM_QUESTOES] = { // inicializacao do vetor
        'a', 'b', 'c', 'd', 'e', 'e', 'd', 'c', 'b', 'a',
        'a', 'a', 'b', 'b', 'c', 'c', 'd', 'd', 'e', 'e'
    };
    char respostas[NUM_QUESTOES] = {}; // tudo zerado

    printf("Digite as respostas (a/b/c/d/e) das questoes numeradas a seguir:\n");
    int i;
    for (i=0; i<NUM_QUESTOES; ++i) {
        do {
            printf("Questao %d? ", i+1);
            scanf(" %c", &respostas[i]); // espaco no " %c" para limpar
                                         // a leitura anterior
            respostas[i] = tolower(respostas[i]); // converte pra minuscula
        } while (respostas[i] < 'a' || respostas[i] > 'e'); // usa os codigos
                                                            // numericos na
                                                            // comparacao
    }

    float nota = 0.0;
    for (i=0; i<NUM_QUESTOES; ++i) {
        if (respostas[i] == gabarito[i]) {
            nota += 0.5;
        }
        printf("%d. R: %c, G: %c\n", i+1, respostas[i], gabarito[i]);
    }
    printf("A nota final eh %.1f.\n", nota);

    return EXIT_SUCCESS;
}

