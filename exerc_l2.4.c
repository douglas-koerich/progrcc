#include <stdlib.h>
#include <stdio.h>

int main() {
    float v;
    printf("Digite o preco-base (normal) do ingresso: ");
    scanf("%f", &v);

    int dia_semana;
    printf("Em que dia estamos (1-dom, 2-seg, ..., 7-sab)? ");
    scanf("%d", &dia_semana);

    unsigned idade;
    printf("Idade do(a) espectador(a): ");
    scanf("%u", &idade);

    if (dia_semana == 3) {
        v = v / 2;  // 50% pela terca-feira
    }

    if (idade < 14) {
        v /= 2;     // v *= 0.5; ou v *= 50/100.0;
    }

    printf("O preco final do ingresso eh R$ %.2f.\n", v);

    return EXIT_SUCCESS;
}

