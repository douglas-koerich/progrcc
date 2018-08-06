#include <stdlib.h>
#include <stdio.h>

#if 0
int main(void) {
    char c;     // variavel do tipo char
    char *p;    // variavel do tipo ponteiro-para-char (endereco-de-char)

    p = &c;     // salva o endereco da variavel c na memoria em p

    printf("Digite um caractere: ");
    // scanf(" %c", &c);
    scanf(" %c", p);    // escreve na variavel c (atraves de p) o que for lido do teclado

    char *r;

    /* Poderia ter declarado r junto com p na linha original acima, assim:
    char *p, *r;
    CUIDADO: O exemplo da linha abaixo NAO declara dois ponteiros:
    char *p, r; // p eh um ponteiro-para-char, r eh um char comum
    */

    r = p;  // copia o valor armazenado em p para a variavel r
            // agora, p e r tem ambos o endereco de c
    
    printf("O endereco da variavel c eh %p.\n", r);
    printf("O caractere armazenado nesse endereco eh %c.\n", *p);   // ou *r

    return EXIT_SUCCESS;
}
#endif

int main(void) {
    int c;
    int *p;

    p = &c;

    printf("Digite um inteiro: ");
    scanf("%d", p);

    printf("O endereco da variavel c eh %p.\n", p);
    printf("O valor armazenado nesse endereco eh %d.\n", *p);

    return EXIT_SUCCESS;
}

