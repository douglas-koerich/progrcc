/*
 * Exercicio 14 do capitulo 3 do livro "Fundamentos de Programacao de Computadores"
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
    int ano_nasc, ano_atual;
    printf("Informe o ano de nascimento (AAAA): ");
    scanf("%d", &ano_nasc);
    printf("Agora digite o ano atual (AAAA): ");
    scanf("%d", &ano_atual);

    int anos, meses, dias, semanas;

    anos = ano_atual - ano_nasc;
    meses = anos * 12;
    dias = anos * 365;
    semanas = dias / 7; // apenas semanas inteiras (nao eh divisao real)

    printf("Idade em diferentes medidas:\n");
    printf("Anos: %d\nMeses: %d\nSemanas: %d\nDias: %d\n", anos, meses, semanas, dias);

    return EXIT_SUCCESS;
}