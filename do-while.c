#include <stdio.h>
#include <stdio_ext.h>  // __fpurge

int main() {
    const int ANO_HOJE = 2015;
    int ano_nascimento, idade;

    do {
        printf("Digite seu ano de nascimento: ");

        // Limpa o buffer do teclado para remover "lixo" que seria considerado
        // na proxima leitura do scanf() - resolve o caso de ter sido digitado
        // caracteres alfabeticos ao inves de um numero
        __fpurge(stdin);    // Em Windows: fflush(stdin);

        scanf("%d", &ano_nascimento);
    } while (ano_nascimento < 1900 || ano_nascimento > ANO_HOJE);

    idade = ANO_HOJE - ano_nascimento;

    printf("Voce completa %d anos no ano corrente.\n", idade);

    return 0;
}

