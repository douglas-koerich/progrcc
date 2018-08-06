#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define NUM_QUESTOES 5

int main(void) {
    char gabarito[NUM_QUESTOES] = { 'a', 'b', 'b', 'a', 'e' };
    char prova[NUM_QUESTOES];

    printf("*** DEMO DE PROVA ***\n");
    int q;
    for (q = 0; q < NUM_QUESTOES; ++q) {
        char r;
        do {
            printf("Qual a sua resposta para a questao %d? ", q+1);
            scanf(" %c", &r);
            r = tolower(r); // transforma em minuscula
        } while (r < 'a' || r > 'e');   // usa os codigos como intervalo
        prova[q] = r;
    }

    printf("*** CORRECAO DA PROVA ***\n");
    unsigned acertos = 0;
    for (q = 0; q < NUM_QUESTOES; ++q) {
        if (prova[q] == gabarito[q]) {
            ++acertos;
        }
    }
    printf("Voce acertou %u das %d questoes.\n", acertos, NUM_QUESTOES);
    return EXIT_SUCCESS;
}

