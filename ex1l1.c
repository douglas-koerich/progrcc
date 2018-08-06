#include <stdlib.h>
#include <stdio.h>

int main()
// inicio
{
    // declare segundos : inteiro
    // declare hrs, min, seg : inteiro
    int segundos, hrs, min, seg;

    // leia segundos
    printf("Digite o num. de segundos desde a meia-noite: ");
    scanf("%d", &segundos); // nao esqueca o & (e-comercial)!

    // hrs <- segundos / 3600   ; primeira conversao (quantas horas no total de segundos)
    hrs = segundos / 3600;

    // segundos <- segundos mod 3600    ; a proxima conversao (para minutos) deve ser feita
    //                                  ; sobre o resto dos segundos nao convertidos para horas
    // segundos = segundos % 3600;
    segundos %= 3600;   // operador aglutinado por causa do uso de 'segundos' dos dois lados
                        // da atribuicao

    // min <- segundos / 60
    min = segundos / 60;

    // seg <- segundos mod 60
    seg = segundos % 60;    // como sao variaveis diferentes, aqui nao se aplica o %=

    // escreva hrs:min:seg
    printf("Equivale a %02d:%02d:%02d\n", hrs, min, seg);

    return EXIT_SUCCESS;
// fim
}
