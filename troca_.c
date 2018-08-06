#include <stdio.h>

void nao_troca(int, int);
void troca(int*, int*);

int main() {
    int a = 10, b = 20;

    printf("a=%d, b=%d\n", a, b);

    // TODA passagem de valor para uma funcao implica uma
    // copia do valor da variavel original para a variavel
    // local da funcao
    nao_troca(a, b);

    printf("a=%d, b=%d\n", a, b);

    // Para que uma funcao possa alterar o valor de uma variavel
    // local de outra funcao (como troca vai fazer com a e b que
    // local da funcao
    troca(&a, &b);

    printf("a=%d, b=%d\n", a, b);

    return 0;
}

// x e y recebem uma COPIA de a e b, respectivamente; portanto,
// alteracoes em x e y ***NAO*** se refletem em a e b
void nao_troca(int x, int y) {
    /*
    int aux = x;
    x = y;
    y = aux;
    */
    y = y ^ x;
    x = y ^ x;
    y = y ^ x;
}

// px e py recebem uma COPIA dos ENDERECOS de a e b; assim, eles
// tem acesso indireto para as posicoes de memoria de a e b e
// podem dessa forma alterar seus conteudos/valores
void troca(int* px, int* py) {  // int* px = &a, int* py = &b na chamada
    *py = *py ^ *px;
    *px = *py ^ *px;
    *py = *py ^ *px;
}

