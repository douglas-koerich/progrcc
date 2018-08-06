#include <stdio.h>
#include <math.h>

int main() {
    // Entrada de dados
    float x;
    do {
        printf("Digite o valor de x: ");
        scanf("%f", &x);
    } while (x <= -1.0 || x >= 1.0);    // |x| < 1
    // while (fabs(x) >= 1.0);

    float erro;
    do {
        printf("Digite o erro a ser considerado: ");
        scanf("%f", &erro);
    } while (erro < 0.0);

    // Calculo de f(x), que da o valor de referencia
    float f_x = 1 / (1 - x);    // nao esquecer dos parenteses

    // Laco para ir colocando em f'(x) a contribuicao de cada novo termo,
    // para saber quando f'(x) torna-se tao proximo de f(x) que a diferenca
    // entre eles fica menor que o erro
    float f_linha_x = 0.0;
    int termos = 0; // contador dos termos considerados pelo laco

    while (fabs(f_x - f_linha_x) >= erro) { // fabs() eh a funcao 'modulo': |n|
        // Atualiza f'(x) somando ao que ja foi calculado nas repeticoes
        // anteriores o valor deste termo (x^termos)
        f_linha_x = f_linha_x + pow(x, termos); // uso o contador como expoente, afinal
                                                // a expressao incrementa o expoente na
                                                // mesma ordem de posicao do termo
        // Contabiliza esse termo no total
        ++termos;
    }
    // Impressao do resultado
    printf("Referencia: f(x) = f(%.3f) = %f\n", x, f_x);
    printf("Aproximacao: f'(x) = f'(%.3f) = %f\n", x, f_linha_x);
    printf("Foram necessarios %d termos para diminuir a diferenca abaixo de %f\n", termos, erro);

    return 0;
}

