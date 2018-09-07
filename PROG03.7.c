#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float x; // valor que serah usado para comparacao
    float erro; // diferenca maxima entre f(x) e f'(x) para o dado valor (x)

    do {
        printf("Digite um valor para x (|x|<1): ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);
    printf("Digite o erro maximo entre f(%f) e f'(%f): ", x, x);
    scanf("%f", &erro);

    float f_x = 1 / (1 - x); // valor de referencia

    int termos = 1, expoente = 0;
    float f_linha_x = 1; // valor de f'(x) com apenas o primeiro termo
    while (fabsf(f_x - f_linha_x) >= erro) { // enquanto for maior ou igual ao erro...
        // ... vai colocando um novo termo na serie
        ++expoente, ++termos; // repare no operador virgula que separa expressoes :-)
        f_linha_x += pow(x, expoente);
    }
    printf("Valor de referencia: f(x) = %f\n", f_x);
    printf("Valor aproximado pela serie: f'(x) = %f\n", f_linha_x);
    printf("Foi(ram) necessario(s) %d termo(s) para aproximar abaixo do erro\n", termos);

    return EXIT_SUCCESS;
}

