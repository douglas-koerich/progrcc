#include <stdlib.h> // rand() e srand()
#include <time.h>

int geraAleatorio(int minimo, int maximo) {
    unsigned agora = time(0);

    srand(agora);
    int r = rand();

    if (maximo < minimo) {
        int aux = maximo;   // troca
        maximo = minimo;
        minimo = aux;
    }
    int faixa = maximo - minimo;    // define o tamanho da faixa
                                    // gerada
    r = r % (faixa+1);              // gera um numero dentro da faixa
    r += minimo;                    // ajusta pelo minimo

    return r;
}


