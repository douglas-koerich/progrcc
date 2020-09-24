#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double x, erro; // diferenca (desvio) maxima entre f(x) e f'(x)

    do {
        printf("Digite o valor de x a ser considerado (-1,1): ");
        scanf("%lf", &x);
    } while (x <= -1.0 || x >= 1.0);

    do {
        printf("Digite o erro maximo (>0): ");
        scanf("%lf", &erro);
    } while (erro <= 0.0);

    // Valor calculado de f(x) - funcao exata - para o valor dado de x
    double f_x = 1 / (1 - x);

    // Inicia o somatorio com nenhum termo
    double f_linha = 0.0;
    int termos = 0;

    while (fabs(f_linha - f_x) >= erro) { // fabs() para pegar o modulo da diferenca e compara-lo com o erro
        /*
        f_linha += pow(x, termos);
        ++termos;
        */
        f_linha += pow(x, termos++); // vai incrementar DEPOIS de usar o valor de 'termos' na funcao pow()
    }

    printf("Foram necessarios %d termos para diminuir a diferenca abaixo do erro\n", termos);
    printf("f(x) = %lf\n", f_x);
    printf("f'(x) = %lf\n", f_linha);

    return EXIT_SUCCESS;
}