#include <stdlib.h>
#include <stdio.h>

char c1 = 'a', c2 = 'e', c3 = 'i';
int i1 = 10, i2 = 200, i3 = -5;

int main(void) {
    char* pc = &c2;
    int* pi = &i2;

    printf("O endereco armazenado em pc eh %p, e nessa posicao estah o caracter %c.\n", pc, *pc);
    --pc;
    printf("O endereco armazenado em pc eh %p, e nessa posicao estah o caracter %c.\n", pc, *pc);
    pc += 2;
    printf("O endereco armazenado em pc eh %p, e nessa posicao estah o caracter %c.\n", pc, *pc);

    printf("O endereco armazenado em pi eh %p, e nessa posicao estah o numero %d.\n", pi, *pi);
    --pi;   // Note que o numero nao eh decrementado de 1, mas de 4, que eh a distancia para o inteiro anterior!
    printf("O endereco armazenado em pi eh %p, e nessa posicao estah o numero %d.\n", pi, *pi);
    pi += 2;    // Novamente, perceba que a soma += 2 eh feita de maneira que ele vai para 2 inteiros a frente
    printf("O endereco armazenado em pi eh %p, e nessa posicao estah o numero %d.\n", pi, *pi);

    return EXIT_SUCCESS;
}
