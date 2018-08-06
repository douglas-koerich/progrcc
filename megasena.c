#include <stdlib.h>
#include <stdio.h>

// Declaracao da funcao 'fatorial' (prototipo)
double /* tipo do retorno */ fatorial(unsigned /* tipo do (unico) parametro */);

int main() {
    // Probabilidade de acertar os seis numeros da mega-sena eh, por
    // analise combinatoria, uma entre todas as Combinacoes de 60 elementos,
    // com 6 elementos dos mesmos em cada uma
    // C = ___n!___ = ___60!___
    //     (n-p)!p!   (60-6)!6!

    const unsigned NUM_TOTAL_ELEMENTOS = 60;    // (n)
    const unsigned NUM_ELEMENTOS_COMB = 6;      // (p)

    double produto_total, produto_comb, produto_diferenca;

    // Primeiro fatorial: 60!
    produto_total = fatorial(NUM_TOTAL_ELEMENTOS);
    /*
    unsigned i;
    for (produto_total = 1.0, i = NUM_TOTAL_ELEMENTOS; i >= 1; --i) {
        produto_total *= i;
    }
    */

    // Segundo fatorial: 6!
    produto_comb = fatorial(NUM_ELEMENTOS_COMB);
    /*
    for (produto_comb = 1.0, i = NUM_ELEMENTOS_COMB; i >= 1; --i) {
        produto_comb *= i;
    }
    */

    // Terceiro fatorial: (60-6)!
    produto_diferenca = fatorial(NUM_TOTAL_ELEMENTOS-NUM_ELEMENTOS_COMB);
    /*
    for (produto_diferenca = 1.0, i = NUM_TOTAL_ELEMENTOS-NUM_ELEMENTOS_COMB; i >= 1; --i) {
        produto_diferenca *= i;
    }
    */

    unsigned combinacoes = produto_total / (produto_comb * produto_diferenca);

    printf("Voce tem 1 em %u chances de acertar na mega-sena!\n", combinacoes);

    return EXIT_SUCCESS;
}

// Definicao da funcao ("corpo"/bloco de codigo do algoritmo): implementacao
double fatorial(unsigned numero) { // 'numero' tambem eh uma variavel LOCAL da funcao
    unsigned i; // 'i' eh uma variavel LOCAL (e TEMPORARIA) da funcao 'fatorial'
    double produto; // 'produto' tambem eh LOCAL!
    for (produto = 1.0, i = numero; i >= 1; --i) {
        produto *= i;
    }
    return produto;
}

