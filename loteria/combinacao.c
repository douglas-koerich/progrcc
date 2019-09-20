#include "combinacao.h" // prototipo da funcao definida neste arquivo-fonte
#include "fatorial.h"   // prototipo da funcao de outro arquivo-fonte usada aqui

double combinacao(double n, double p) {
    double fat_n = fatorial(n);
    double fat_p = fatorial(p);
    double fat_n_menos_p = fatorial(n-p);
    double comb = fat_n / (fat_p * fat_n_menos_p);
    return comb;
}

