#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double serie(int);

int main(void) {
    int N;
    double S;

    printf("Digite o numero de termos (N): ");
    scanf("%d", &N);
    S = serie(N);
    printf("O somatorio resulta %.5lf.\n", S);

    return EXIT_SUCCESS;
}

double serie(int N) {
    double S = 0.0; // inicializa total do somatorio
    int n;          // controle do laco/somatorio
    for (n=1; n<=N; ++n) {
        S += (pow(n, 2) + 1) / (n+3);
    }
    return S;
}
