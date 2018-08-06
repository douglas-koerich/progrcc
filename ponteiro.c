#include <stdio.h>

int main() {
    int x = 10, y = 20;
    int* p = &x, *p1;   // ponteiro nao inicializado eh perigoso...

    printf("O endereco no ponteiro nao-inicializado eh %p\n", p1);
    /*
    printf("(PERIGO) O valor apontado pelo ponteiro nao-inicializado eh %d\n", *p1);
    *p1 = 100;
    */

    p1 = p; // copia o endereco armazenado em p para p1
            // (agora ambos apontam para x)
    printf("O endereco no ponteiro nao-inicializado agora eh %p\n", p1);

    char c = 'A';
    char *p2 = &c;
    float *pf = NULL;   // ponteiro INVALIDO mas com certeza invalido

    // Vou imprimir o valor de endereco armazenado em cada ponteiro
    // Note que ***NAO*** eh usado nenhum operador nesse caso, estou
    // imprimindo o valor das variaveis-ponteiros como faco para uma
    // variavel de tipo qualquer
    printf("O endereco da variavel inteira eh %p\n", p);
    printf("O endereco da variavel caracter eh %p\n", p2);

    // Imprimindo os valores armazenados nos enderecos usando os ponteiros
    // ao inves das proprias variaveis para chegar nesses valores
    printf("O valor armazenado em x eh %d\n", *p);
    printf("O valor armazenado em c eh %c\n", *p2);

    p = &y; // mudei a variavel apontada por p
    printf("O novo endereco em p eh %p e seu conteudo eh %d\n", p, *p);

    // O compilador sabe distinguir o asterisco da multiplicacao do
    // asterisco do acesso ao conteudo (que na ordem de precedencia dos
    // operadores vem primeiro)
    printf("A multiplicacao de x por y eh %d\n", *p1 * *p);

    *p1 = 30;   // mudei o valor de x!!!
    printf("x agora vale %d\n", x);

    return 0;
}

