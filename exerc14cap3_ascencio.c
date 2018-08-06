#include <stdlib.h>
#include <stdio.h>

int main() {
    int ano_atual, ano_nascimento, idade_atual, idade_2050;

    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);

    printf("Digite o ano do nascimento: ");
    scanf("%d", &ano_nascimento);

    idade_atual = ano_atual - ano_nascimento;
    idade_2050 = 2050 - ano_nascimento;

    // Ou: idade_2050 = idade_atual + (2050 - ano_atual)

    printf("A idade atual eh %d.\n", idade_atual);
    printf("A idade em 2050 serah %d.\n", idade_2050);
    
    return EXIT_SUCCESS;
}
