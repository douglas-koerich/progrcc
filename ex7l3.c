#include <stdlib.h>
#include <stdio.h>
#include <math.h> // fabsf

int main() {
    float x;
    do {
        printf("Digite um valor para x: ");
        scanf("%f", &x);
    } while (fabsf(x) >= 1.0); // v. pagina de manual ("man fabsf")

    float erro;
    do {
        printf("Digite o erro maximo a ser considerado na aproximacao: ");
        scanf("%f", &erro);
    } while (erro < 0); // nao aceita erros negativos

    float f_x, f_linha_x, diferenca;
    int termos = 0;

    f_x = 1 / (1 - x); // aplicacao direta da formula
    f_linha_x = 0.0;   // serie resulta num somatorio...
    while ((diferenca = fabsf(f_x - f_linha_x)) >= erro) { // calcula 'diferenca'
                                                           // DENTRO do while
        ++termos; // eh necessario um novo termo
        f_linha_x += pow(x, termos-1); // soma o novo termo ao resultado da serie
    }

    printf("Foram necessarios %d termos para aproximar f(%f)=%f e f'(%f)=%f\n",
           termos, x, f_x, x, f_linha_x);

    return EXIT_SUCCESS;
}

