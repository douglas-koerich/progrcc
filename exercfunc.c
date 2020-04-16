#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float calcula_pi(int);

int main(void) {
    int termos;
    do {
        printf("Quantos termos serao usados para calcular o valor de \"Pi\"? ");
        scanf("%d", &termos);
    } while (termos > 50);

    float pi = calcula_pi(termos);

    printf("O numero \"Pi\" calculado pela serie eh %f\n", pi);

    return EXIT_SUCCESS;
}

float calcula_pi(int termos) {
    if (termos <= 0) {
        return 0.0;
    }
    float S = 0.0; // inicializa a variavel do somatorio
    int t, num;
    for (t = 1, num = 1; t <= termos; ++t, num += 2) {
        float termo = 1.0 / pow(num, 3);
        if (t % 2 != 0) { // termo de ordem impar?
            S += termo;
        } else { // termo de ordem par?
            S -= termo;
        }
    }
    // Como nao temos a operacao de raiz-cubica como uma funcao em C, precisamos
    // usar os conhecimentos de Matematica, lembrando que a radiciacao eh a operacao
    // INVERSA da potenciacao
    float pi = pow(S * 32, 1.0/3); // lembre-se de usar uma divisao real aqui, do
                                   // contrario 1/3 = 0 (!!!) e o resultado serah
                                   // sempre igual a 1
    return pi;
}

