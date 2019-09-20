#include "fatorial.h"

double fatorial(double x) {
    if (x < 0.0) {
        return 0.0;
    }
    double f = 1.0, i;
    for (i = 1.0; i <= x; ++i) {
        f *= i;
    }
    return f;
}
