/* Formula do juro composto: Vf = Vi(1+i)^N, onde:
Vf = capital final
Vi = capital inicial
i = taxa de juros
N = periodo de aplicacao (numero de unidades de tempo)
*/

#include <math.h>
#include "juros.h"

double valor_final(double valor_inicial, double taxa, unsigned periodo) {
    return valor_inicial * pow(1 + taxa/100.0, periodo);
}
