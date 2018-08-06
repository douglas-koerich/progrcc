#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int x;  // esta variavel eh um inteiro com o qual posso operar algebricamente
    int *p; // esta variavel tem o ENDERECO de algum inteiro, soh posso usar esse
            // numero (o endereco) como referencia (nao ha aritmetica - ou quase...)

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    // Posso usar a variavel-ponteiro para "conhecer" o endereco da variavel x
    // (e, portanto, do seu valor armazenado) na memoria
    p = &x; // & = o endereco da variavel 'tal' (x, nesse caso)
    printf("A variavel x foi alocada no endereco %p da memoria.\n", p);

    int y = x * 2;

    // Tambem poderia fazer referencia `a mesma posicao de memoria rotulada
    // como x de outra maneira, usando agora o ponteiro
    y = *p * 2; // * = o valor que esta armazenado no endereco 'tal' (p, nesse caso)

    printf("O dobro do valor digitado eh %d.\n", y);

    return EXIT_SUCCESS;
}
