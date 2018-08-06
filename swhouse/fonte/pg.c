#ifdef IMPRIME_MSG  // compilacao condicional
#include <stdio.h>
#endif

int pg_termo_n(int a1, int q, int n) {
    int pot = 1;
    int m;
    for (m=1; m<n; ++m) {
        pot *= q;
    }
    int an = a1 * pot;
    return an;
}

int pg_soma_n(int a1, int q, int n) {
#ifdef IMPRIME_MSG
    printf("pg_soma_n foi chamada com q = %d.\n", q);
#endif
    if (q == 1) {
        return 0;
    }
    int pot = 1;
    int m;
    for (m=1; m<=n; ++m) {
        pot *= q;
    }
    int S = a1 * (pot-1) / (q-1);
    return S;
}
