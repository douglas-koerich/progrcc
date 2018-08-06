#include <stdio.h>

int main() {
    // Dados de entrada
    float Y;
    int N;

    // Variavel de controle do laco/produtorio
    int i;

    // Leitura dos dados de entrada
    printf("Digite o valor de Y: ");
    scanf("%f", &Y);

    do {
        printf("Digite o numero de termos da serie (N): ");
        scanf("%d", &N);
    } while (N <= 0);   // porque i comeca em 1 na formula

    // Variavel de saida: resultado do produtorio (do laco)
    /*
    float P = 1.0;  // elemento neutro da multiplicacao, usado para a
                    // primeira repeticao do laco
    */
    float P;
    int fatorial, x;
    for (i=1, P=1.0; i<=N; ++i) {   // inicializo P junto com i
        // Cada termo/repeticao precisa de um novo calculo de fatorial,
        // para ser usado como denominador; entao, existe um laco interno
        // para calcular o produtorio=fatorial
        for (x=fatorial=1; x <= i-1; ++x) { // x e fatorial recebem 1
           fatorial = fatorial * x; // fatorial *= x;
        }
        // Calcula o termo da vez, multiplicando-o pelo acumulado do
        // produtorio (P) ateh agora
        P = P * Y / fatorial;   // P *= Y / fatorial;
    }

    // Resultado final
    printf("O produtorio calculado eh %f\n", P);

    return 0;
}
