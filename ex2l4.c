#include <stdlib.h>
#include <stdio.h>

void gera_num_fibonacci(unsigned N, unsigned valor) {
    // Serie de Fibonacci
    // 0,1,1,2,3,5,8,13,21,34,...
    if (N == 0) {
        puts("0");
        return; // nao ha valor a ser devolvido pelo procedimento
    }
    unsigned n_menos_2 = 0, n_menos_1 = 1, contador = 0;
    while (contador < N) {
        unsigned n = n_menos_2 + n_menos_1;
        if (n > valor) {
            printf("%u ", n); // soh imprime se for maior que 'valor'
            ++contador;
        }
        n_menos_2 = n_menos_1;
        n_menos_1 = n;
    }
    
    putchar('\n');

    // nao ha porque usar 'return;' nesta linha (eh a ultima a ser executada)
}

int main(void) { // main() nao recebe nenhum parametro/valor de entrada
    unsigned valor;
    printf("Digite um valor de referencia: ");
    scanf("%u", &valor);

    unsigned qtde;
    printf("Quantos numeros de Fibonacci deseja gerar maiores que %u? ", valor);
    scanf("%u", &qtde);

    gera_num_fibonacci(qtde, valor); // qtde eh passada como N pra funcao

    return EXIT_SUCCESS;
}

