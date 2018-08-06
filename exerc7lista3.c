#include <stdlib.h>
#include <stdio.h>
#include <math.h> // usado em pow() e fabs()

int main() {
    // Variaveis de entrada: x e o desvio/erro/tolerancia entre f(x) e f'(x)
    float x, erro;
    
    // Variavel de saida: numero de termos necessarios
    unsigned num_termos;

    do {
        printf("Digite o valor de x: ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);
    do {
        printf("Digite o erro aceitavel: ");
        scanf("%f", &erro);
    } while (erro <= 0.0 || erro > 1.0); // erro absoluto (em modulo)

    // Vamos calcular o valor original de f(x), que serah a _referencia_ para
    // encontrarmos o valor aproximado
    float f_x = 1 / (1 - x);

    // Inicializamos o valor de aproximacao f'(x) com zero ao mesmo tempo que
    // zeramos o contador de termos
    float f_linha_x = 0.0;
    num_termos = 0;

    // Laco para repetir a inclusao de cada novo termo enquanto o erro nao for
    // satisfeito...
    while (fabs(f_x - f_linha_x) >= erro) {
        float novo_termo = pow(x, num_termos++); // usa mais um termo e o conta
        f_linha_x += novo_termo;
    }
    
    // Imprime o resultado da aproximacao
    printf("Foram necessarios %u termos para f'(x)=%f se aproximar de f(x)=%f.\n",
           num_termos, f_linha_x, f_x);

    return EXIT_SUCCESS;
}

