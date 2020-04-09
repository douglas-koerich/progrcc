#include "fatorial.h"

double fact(double numero) {
    double fatorial = 1.0; // variavel local ao INTERIOR da funcao fact
    int x;
    for (x = 1; x <= numero; ++x) {
        fatorial *= x; // fatorial = fatorial * x;
    }
    return fatorial;
}

