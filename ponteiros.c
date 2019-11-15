#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i; // variavel do tipo inteiro original

    int* p; // variavel do tipo ponteiro-para-inteiro

    /*
    printf("Digite um numero: ");
    scanf("%d", &i);
    */

    printf("O endereco inicial armazenado no ponteiro eh %p.\n", p);
    if (p == NULL) { // NULL = 0
        puts("O endereco inicial eh NULO (invalido)!");
    }

    // Para salvar o endereco de algo (normalmente, uma variavel) num
    // ponteiro usamos o operador & ("endereco de X")
    p = &i;

    printf("Depois da atribuicao o endereco no ponteiro eh %p.\n", p);

    printf("Digite um numero: ");
    scanf("%d", p); // sem o & na frente do p, pois p = &i (v. original)

    // Para ler de (ou escrever em) uma posicao de memoria da qual se
    // conhece o endereco salvo num ponteiro, usamos o operador * ("conteudo
    // no endereco X")
    // if (i % 2 == 0) {
    if (*p % 2 == 0) { // *p devolve o valor contido no endereco salvo em p
        puts("Voce digitou um numero par!");
    } else {
        puts("Voce digitou um numero impar!");
    }
    return EXIT_SUCCESS;
}

