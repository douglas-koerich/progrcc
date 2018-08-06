/*
 * pa_pg.c: Arquivo-fonte com as funcoes relativas as operacoes
 * basicas com series de progressao aritmetica (P.A.) e geometrica (P.G.)
 */

#include <stdlib.h> // para definicao do tipo size_t (contador/quantidade)
#include <math.h>   // uso de pow() nas funcoes
#include "pa_pg.h"  // para conferencia em tempo de compilacao

// Funcao que calcula o termo geral de uma P.A.
// Entradas: primeiro termo (a1), numero de termos (n) e razao (r)
// Saida: n-esimo termo (an)
int termo_geral_pa(int a1, int r, size_t n) {
    int an;
    an = a1 + (n - 1) * r;
    return an;
}

// Funcao que calcula a soma dos 'n' primeiros termos de uma P.A.
// Entradas: primeiro termo (a1), n-esimo termo (an) e numero de termos (n)
// Saida: soma dos termos (Sn)
int soma_n_termos_pa(int a1, int an, size_t n) {
    int Sn;
    Sn = (a1 + an) * n / 2;
    return Sn;
}

// Funcao que calcula o termo geral de uma P.G.
// Entradas: primeiro termo (a1), numero de termos (n) e razao (q)
// Saida: n-esimo termo (an)
int termo_geral_pg(int a1, int q, size_t n) {
    int an;
    an = a1 * pow(q, n - 1);
    return an;
}

// Funcao que calcula a soma dos 'n' primeiros termos de uma P.G.
// Entradas: primeiro termo (a1), numero de termos (n) e razao (q)
// Saida: soma dos termos (Sn)
int soma_n_termos_pg(int a1, int q, size_t n) {
    int Sn;
    Sn = a1 * (pow(q, n) - 1) / (q - 1);
    return Sn;
}

