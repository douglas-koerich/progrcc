#include <stdlib.h>
#include <stdio.h>

int main() {
    float v;    // valor do ingresso
    int idade, dia_da_semana;

    printf("Que dia eh hoje (1=dom, 2=seg, ..., 7=sab)? ");
    scanf("%d", &dia_da_semana);
    printf("Qual a idade do(a) espectador(a)? ");
    scanf("%d", &idade);
    printf("Qual eh o valor atual do ingresso (R$)? ");
    scanf("%f", &v);

    if (dia_da_semana == 3) {
        v = v / 2;  // 50%
    }
    if (idade < 14) {
        v *= 0.5;
    }

    printf("O valor do ingresso para esse(a) espectador(a) eh R$ %.2f.\n", v);
    
    return EXIT_SUCCESS;
}
