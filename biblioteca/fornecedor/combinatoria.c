#include "fatorial.h"

// P(n) = n!
int permutacao(int n) {
    return fatorial(n);
}

// A(n,p) = n! / (n-p)!
int arranjo(int n, int p) {
    return fatorial(n) / fatorial(n-p);
}

// C(n,p) = n! / ((n-p)! * p!)
int combinacao(int n, int p) {
    return fatorial(n) / (fatorial(n-p) * fatorial(p));
}

