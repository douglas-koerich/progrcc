#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float calculaSomatorio(unsigned);

int main(void) {
    unsigned N;
    printf("Digite um numero inteiro e positivo: ");
    scanf("%u", &N);
    float S = calculaSomatorio(N);
    printf("O somatorio (S) da serie eh %f\n", S);
    return EXIT_SUCCESS;
}

float calculaSomatorio(unsigned N) {
    int n;
    float S;
    for (n=1, S=0.0; n<=N; ++n) {
        S += (pow(n, 2) + 1) / (n + 3);
    }
    return S;
}

