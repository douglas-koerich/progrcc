/**
 * Deste ponto...
 */

#include <stdio.h>
#include <math.h>

double pi(double);

int main() {
    double erro;
    printf("Qual a diferenca tolerada entre as series? ");
    scanf("%lf", &erro);
    printf("O valor de PI encontrado foi %lf.\n", pi(erro));
    return 0;
}

/**
 * ... ate aqui nao eh parte da questao, mas se fosse feita com PC precisava
 * ser implementada.
 */

double pi(double erro) {    // poderia ser float :-)
    double pi1 = 4.0,               // primeiro termo da serie (1) (ja eh PI)
           S = 1.0,                 // primeiro termo da serie (2) (nao eh PI)
           pi2 = pow(S*32, 1/3.0),  // primeiro PI obtido a partir de (2)
           denominador = 1.0;       // primeiro denominador de ambas (1) e (2)
    int N = 1, M = 1;               // comeca com 1 nos contadores porque os
                                    // valores iniciais de pi1 e pi2 ja sao
                                    // conhecidos e podem ser comparados
    while (fabs(pi2 - pi1) >= erro) {   // poderia fazer o modulo "na mao"
        denominador += 2;
        ++N;                // comeca por (2) pra ver se ja satisfaz a parada
        if (N % 2 == 0) {   // pra decidir se soma ou diminui este N-esimo termo
            S -= 1 / pow(denominador, 3);
        }
        else {
            S += 1 / pow(denominador, 3);   // note que a formula eh a mesma
        }
        pi2 = pow(S*32, 1/3.0); // 3.0? note que a divisao tem que ser REAL!
        if (fabs(pi2 - pi1) < erro) {
            // Nao precisa continuar na serie (1), ja alcancou a diferenca!
            printf("N = %d, M = %d\n", N, M);
            return pi2;
        }
        ++M;                // agora vai por mais um termo em (1) pra testar
        if (M % 2 == 0) {   // mesma verificacao pra saber se +/-
            pi1 -= 4 / denominador;
        }
        else {
            pi1 += 4 / denominador;
        }
    }
    // Se saiu do laco eh porque a diferenca entre pi1 e pi2 ficou menor
    printf("N = %d, M = %d\n", N, M);
    return pi2;
}

