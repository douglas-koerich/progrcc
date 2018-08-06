#include <stdlib.h>
#include <stdio.h>
#include "pa.h"
#include "pg.h"

int main(void) {
    printf("+++ PROGRESSAO ARITMETICA +++\n");
    printf("Digite o primeiro termo: ");
    int arit1;
    scanf("%d", &arit1);
    printf("Digite a razao da progressao: ");
    int aritR;
    scanf("%d", &aritR);

    printf("xxx PROGRESSAO GEOMETRICA xxx\n");
    printf("Digite o primeiro termo: ");
    int prog1;
    scanf("%d", &prog1);
    printf("Digite a razao da progressao: ");
    int progR;
    scanf("%d", &progR);

    printf("Qual eh a posicao do termo que serah calculado nas duas progressoes? ");
    int n;
    scanf("%d", &n);

    int aritn = pa_termo_n(arit1, aritR, n);
    int aritS = pa_soma_n(arit1, aritn, n);

    int progn = pg_termo_n(prog1, progR, n);
    int progS = pg_soma_n(prog1, progR, n);

    printf("O %do. termo da PA eh %d e a soma dos %d termos eh %d.\n", n, aritn, n, aritS);
    printf("O %do. termo da PG eh %d e a soma dos %d termos eh %d.\n", n, progn, n, progS);

    return EXIT_SUCCESS;
}
