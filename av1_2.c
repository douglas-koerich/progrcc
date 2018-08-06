#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Inicio da solucao:
 * (nao eram pedidos prototipo nem main()
 */

float aproxima(float primeira, int numero) {
    float x_n = primeira, x_n_mais_1;
    int i;
    for (i=1; i<=numero; ++i) {
        float numerador = pow(x_n, 3) - 3 * pow(x_n, 2) + 1;
        float denominador = 3 * pow(x_n, 2) - 6 * x_n;
        x_n_mais_1 = x_n - numerador / denominador;
        x_n = x_n_mais_1;
    }
    return x_n_mais_1;
}

/* Fim da solucao
 * Funcao main() incluida aqui apenas pra teste/demonstracao
 */

int main(void) {
    printf("Uma raiz da equacao eh %f.\n", aproxima(1.5, 20));
    return EXIT_SUCCESS;
}
