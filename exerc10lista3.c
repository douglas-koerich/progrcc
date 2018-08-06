#include <stdlib.h>
#include <stdio.h>

int main() {
    // Unico dado de entrada: o numero de divisoes (n) que define quantos
    // trapezios serao utilizados na aproximacao
    int n;
    printf("Digite o numero de divisoes do intervalo de integracao: ");
    scanf("%d", &n);

    // Como a e b sao fixos na formula, ja posso calcular a altura de todos os
    // trapezios, que eh o "delta-x"
    int a = 0, b = 1;
    float delta_x = (float)(b-a)/n; // "cast": considera (b-a) como float, do contrario
                                    // faria uma divisao inteira (pq todas as variaveis sao int)

    // Todo variavel do valor acumulado de um somatorio ou produtorio num laco
    // tem que ser inicializada com o elemento neutro da operacao (nesse caso, zero)
    float S = 0.0;
    int num_area; // eh o 'i' da formula no enunciado
    float xi_1 = a, xi = a+delta_x;
    for (num_area = 1; num_area <= n; ++num_area) {
        float yi_1 = 1 / (1 + xi_1*xi_1);   // uso a formula de f(x)
        float yi = 1 / (1 + xi*xi);
        float area = (yi + yi_1)/2 * delta_x;
        S += area;
        xi_1 = xi;
        xi = xi + delta_x;
    }
    printf("O valor aproximado de PI eh %.5f.\n", 4*S);

    return EXIT_SUCCESS;
}
