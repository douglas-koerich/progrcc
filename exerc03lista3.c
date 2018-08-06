#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned N;
    float Y, P;

    // Dados de entrada: N e Y
    printf("Qual o valor de Y usado no produtorio? ");
    scanf("%f", &Y);
    printf("Quantos termos serao usados? ");
    scanf("%u", &N);

    // Laco que implementa o produto dos termos
    unsigned i; // i representa alem do valor na formula o termo da vez
    P = 1.0;  // inicia o produto com 1 (elemento neutro da multiplicacao)
    for (i=1; i<=N; ++i) {
        // Em cada passo do laco, calcula-se o valor do termo para depois
        // multiplica-lo ao valor de P resultante dos passos anteriores
        // Antes, porem, preciso calcular o fatorial "na mao", uma vez que nao
        // existe funcao em C pra isso (um laco interno!)
        // unsigned j, fatorial = 1;   // valor inicial do fatorial
        unsigned j, fatorial;
        for (j=1, fatorial=1; j<=(i-1); ++j) {
            fatorial = fatorial * j;    // fatorial *= j;
        }
        float termo = Y/fatorial;
        P *= termo;
    }
    printf("O produtorio resultante eh %.3f.\n", P);

    return EXIT_SUCCESS;
}
