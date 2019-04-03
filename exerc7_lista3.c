#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float x; // |x| < 1 precisa ser fracionario
    float erro;

    printf("Digite o erro maximo (tolerancia): ");
    scanf("%f", &erro);

    do {
        printf("Digite o valor de x: ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);

    float f_x = 1 / (1 - x); // calcula o valor original (de referencia)

    int termos = 0;
    float f_linha_x = 0.0;

    while (fabsf(f_x - f_linha_x) >= erro) { // usa fabsf porque nao sabe qual
                                             // sera maior, se f(x) ou o valor
                                             // acumulado de f'(x) ateh aqui
        /*
        f_linha_x += pow(x, termos); // usa a variavel 'termos' como expoente
                                     // de cada novo termo de x em f'(x)
        ++termos;
        */
        // As duas linhas acima podem ser condensadas na linha:
        f_linha_x += pow(x, termos++); // incrementa 'termos' DEPOIS de usar
    }
    printf("Foram necessarios %d termos.\n", termos);
    printf("f(x) = %f\n", f_x);
    printf("f'(x) = %f\n", f_linha_x);

    return EXIT_SUCCESS;
}

