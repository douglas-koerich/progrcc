#include <stdio.h>

int main() {
    float v;
    int dia, idade;

    printf("Valor do ingresso (R$)? ");
    scanf("%f", &v);
    printf("Dia da semana (1=dom, 2=seg, ..., 7=sab)? ");
    scanf("%d", &dia);
    printf("Idade do(a) espectador(a)? ");
    scanf("%d", &idade);

    if (dia == 3) {
        v *= 0.5;
    }
    if (idade < 14) {
        v *= 0.5;
    }

    printf("O valor final do ingresso eh %.2f\n", v);

    return 0;
}

