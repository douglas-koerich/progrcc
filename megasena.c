#include <stdlib.h>
#include <stdio.h>
#include "fatorial.h"

int main() {
    int n = 6;
    // probabilidade = C = 60! / ((60 - n)! * n!)
    double probabilidade = fact(60) / (fact(60-n) * fact(n));

    // Veja como se "quebra" uma frase entre aspas em 2 linhas na linguagem C
    printf("Voce tem 1 chance em %.0lf de acertar a megasena com "
           "uma aposta simples\n", probabilidade);

    return EXIT_SUCCESS;
}
