#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int resolve_polinomio(int [*], unsigned, int);

int main(void) {
    unsigned grau;
    printf("Digite o grau do polinomio: ");
    scanf("%u", &grau);

    // Vetor de coeficientes eh declarado com o tamanho justo
    // para o numero de termos equivalente ao grau informado
    int coeficientes[grau+1];   // vetor de tamanho variavel

    // Preenche o vetor de acordo com os expoentes dos termos
    int g;
    for (g = grau; g >= 0; --g) {
        printf("Digite o coeficiente (inteiro) do grau %d: ", g);
        scanf("%d", &coeficientes[g]);  // preenchendo do fim p/ inicio
    }
    // Imprime o polinomio na forma extensa
    printf("Voce digitou o polinomio ");
    for (g = grau; g >= 0; --g) {
        if (coeficientes[g] == 0) {
            continue;
        }
        if (coeficientes[g] > 0) {
            printf("+");
        }
        printf("%d", coeficientes[g]);  // imprime o coeficiente
        if (g >= 1) {
            printf("x");
            if (g > 1) {
                printf("^%d", g);
            }
        }
    }
    printf("\n");

    int x;
    printf("Qual o valor de x a ser aplicado no polinomio? ");
    scanf("%d", &x);

    printf("O polinomio resulta %d.\n", resolve_polinomio(coeficientes, grau, x));

    return EXIT_SUCCESS;
}

int resolve_polinomio(int v[], unsigned g, int x) {
    int soma = 0, expoente;
    for (expoente = 0; expoente <= g; ++expoente) {
        soma += v[expoente] * pow(x, expoente);
    }
    return soma;
}

