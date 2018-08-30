#include <stdlib.h>
#include <stdio.h>

int main() {
    int dia_semana; // 1 = dom, 2 = seg, ..., 7 = sab
    int idade;
    float v; // preco oficial do ingresso no cinema X

    printf("Digite o dia da semana (1 para Dom, ..., 7 para Sab): ");
    scanf("%d", &dia_semana);
    printf("Qual a idade do(a) espectador(a)? ");
    scanf("%d", &idade);
    printf("Digite o preco oficial: ");
    scanf("%f", &v);

    float pagar = v; // comeca o valor a pagar com o valor cheio
    if (dia_semana == 3) { // terca-feira?
        pagar *= 0.5;
    }
    if (idade < 14) { // menor de 14 anos
        pagar *= 0.5;
    }
    printf("O valor a pagar pelo ingresso eh %.2f\n", pagar);

    return EXIT_SUCCESS;
}

