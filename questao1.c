#include <stdlib.h>
#include <stdio.h>

void imprime_fibonacci(int, int, int);

int main(void) {
    imprime_fibonacci(5, 3, 2);
    putchar('\n'); // pra nao "colar" com o prompt do terminal
    return EXIT_SUCCESS;
}

void imprime_fibonacci(int N, int i, int j) {
    if (N <= 0 || i <= 0 || j <= 0) {
        return;
    }
    int f0, f1, f2; // os numeros de Fibonacci que vao sendo calculados
                    // Lembrando: f2 = f1 + f0
    int n; // numero de termos impressos (ateh N)
    int f; // em qual numero de fibonacci estou (imprime se f >= i)
    int k; // "contador" pra controlar a impressao de j em j

    f0 = 1, f1 = 2; // os primeiros numeros de Fibonacci
    n = 0; // nenhum numero impresso ainda
    f = 1; // comeca a geracao pelo primeiro termo (f0)
    k = j; // quantos numeros faltam pra "imprimir de novo"

    while (n < N) { // porque n comeca com 0
        if (f >= i) { // jah posso imprimir?
            if (k == j) { // posso imprimir de novo?
                printf("%d ", f0); // imprime o Fibonacci "da vez"
                ++n; // conta o numero que foi impresso como mais um termo
            }
            --k; // pra controlar quando chega em j de novo...
            if (k == 0) {
                k = j;
            }
        }
        f2 = f0 + f1; // calcula o Fibonacci seguinte e...
        f0 = f1;      // ... "caminha" com a dupla de numeros...
        f1 = f2;      // ... para ter os valores que serao usados no calculo
                      // seguinte (proxima iteracao do laco)
        ++f; // numero de termos calculados (nao impressos se f < i)
    }
}

