#include <stdlib.h>
#include <stdio.h>
#include <math.h>   // fabs() e pow()

int main() {
    float x;
    do {
        printf("Digite um numero (|x| < 1): ");
        scanf("%f", &x);
    } while (x >= 1 || x <= -1);    // garantia da entrada de um x valido
    float erro;
    printf("Digite o erro toleravel: ");
    scanf("%f", &erro);

    float original;     // f(x)
    original = 1/(1-x); // usa a formula original de f(x) para o valor dado de x

    int termos = 0, expoente = 0;
    float aproximado = 0;   // inicializa o somatorio
    while (fabsf(original-aproximado) >= erro) { // comparacao em modulo!!!
        aproximado += pow(x, expoente++);        // usa o valor de expoente em pow e DEPOIS incrementa
        // ++expoente;
        ++termos;
        // ++termos, ++expoente;
    }

    printf("O numero de termos necessarios eh %d.\n", termos);
    printf("(OBS: valor original = %f, aproximado = %f)\n", original, aproximado);

    return EXIT_SUCCESS;
}
