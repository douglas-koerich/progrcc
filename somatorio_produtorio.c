/* Escreva um programa que calcule e imprima o somatorio e o produtorio de todos
   os N primeiros numeros pares, onde N eh informado pelo usuario */

#include <stdlib.h>
#include <stdio.h>

int main() {
    int N;
    do {
        printf("Digite N: ");
        scanf("%d", &N);
    } while (N <= 0);
    // somatorio
    int S = 0;  // inicializacao do somatorio (laco vai acumular nessa variavel)
    int i;      // valor que vai mudando de 1 a N (contador) pelo laco
    for (i = 1; i <= N; ++i) {
    // for (i = 1, S = 0; i <= N; ++i) {    // inicializa todas as variaveis que precisa antes do laco
        S += i * 2; // soma o numero par da vez
    }
    // produtorio
    long long int P = 1;  // inicializacao do produtorio (laco vai "acumular"/multiplicar nessa variavel)
    for (i = 1; i <= N; ++i) {
    // for (i = P = 1; i <= N; ++i) {   // i e P sao inicializados juntos valendo 1
        P *= i * 2;
    }
    printf("A soma dos pares eh %d e o produto eh %lld.\n", S, P);

    return EXIT_SUCCESS;
}
