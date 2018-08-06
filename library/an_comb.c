/*
 * an_comb.c: Arquivo-fonte com as funcoes relativas as operacoes
 * fundamentais da analise combinatoria
 */

#include "an_comb.h"    // para conferencia em tempo de compilacao

static int fatorial(int x) {    // 'static' "esconde" fatorial dos demais
                                // modulos (que podem assim ter suas proprias
                                // funcoes 'fatorial'
    int f = 1, i = 1;
    while (i <= x) {
        f *= i++;   // incrementa i DEPOIS de multiplica-lo por f...
    }
    return f;
}

int permutacao(int n) {
    return fatorial(n);
}

int arranjo(int n, int p) {
    return fatorial(n) / fatorial(n - p);
}

int combinacao(int n, int p) {
    return fatorial(n) / (fatorial(n - p) * fatorial(p));
}

