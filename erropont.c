#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int x = 10;
    char c = 'a';
    float f = 3.1416;

    int *pi = 100;   // Nao eh um valor que estah sendo inicializado, eh um endereco!
    char *pc = NULL;    // Eh uma boa pratica inicializar um ponteiro com NULL (0), mas...
    float *pf;

    /*
    // 1o. erro: ... nao se pode "ler" de um ponteiro (endereco) nulo
    printf("O endereco armazenado em pc eh %p.\n", pc);
    printf("O valor armazenado nesse local eh %d.\n", *pc);

    // 2o. erro: utilizar um ponteiro que nao foi atribuido a um endereco valido
    printf("O endereco armazenado em pi eh %p.\n", pi);
    printf("O valor armazenado nesse local eh %d.\n", *pi);

    // 3o. erro: confusao entre ponteiro para inteiro e variavel do tipo inteiro
    pi = x; // ao inves de pi = &x
    printf("O endereco armazenado em pi eh %p.\n", pi);
    printf("O valor armazenado nesse local eh %d.\n", *pi);

    // 4o. erro: uma variante do erro anterior, agora com efeito menos problematico
    x = pi; // ao inves de x = *pi
    printf("O novo valor de x eh %d.\n", x);
    */

    // Uso o operador & para recuperar o endereco de uma variavel (que eh
    // desconhecido a partir do rotulo por ter sido reservado pelo compilador)
    pi = &x; printf("A variavel x estah no endereco %p da memoria.\n", pi);
    pc = &c; printf("A variavel c estah no endereco %p da memoria.\n", pc);
    pf = &f; printf("A variavel f estah no endereco %p da memoria.\n", pf);

    // Uso o operador * para, atraves do ponteiro e NAO da variavel, obter o
    // valor armazenado naquele endereco em questao
    printf("O valor da variavel x eh %d.\n", *pi);
    printf("O valor da variavel c eh %c.\n", *pc);
    printf("O valor da variavel f eh %f.\n", *pf);

    // Inicializacao correta de um ponteiro a partir de outro
    int *p2 = pi;
    p2 = pi;    // a mesma operacao correta, agora como atribuicao

    /*
    // 5o. erro: utilizar o operador * na copia de endereco entre ponteiros
    p2 = *pi;

    // 6o. erro: para o mesmo fim, utilizar o operador &
    p2 = &pi;   // ao inves de copiar o endereco de x que esta armazenado em pi,
                // acabei armazenando em p2 o endereco da variavel pi
    */

    printf("A variavel x estah no endereco %p da memoria.\n", p2);
    printf("O valor da variavel x eh %d.\n", *p2);

    /*
    // 7o. erro: utilizar o ponteiro de tipo errado
    pf = &x;    // pf eh do tipo float*, mas x eh um inteiro
    printf("A variavel x estah no endereco %p da memoria.\n", pf);
    printf("O valor da variavel x eh %d.\n", *pf);

    // 8o. erro, mascarado pelo fato que um caracter eh um codigo numerico!
    pi = &c;    // pi eh do tipo int*, max c eh um caracter
    printf("A variavel c estah no endereco %p da memoria.\n", pi);
    printf("O valor da variavel c eh %c.\n", *pi);
    */

    return EXIT_SUCCESS;
}

