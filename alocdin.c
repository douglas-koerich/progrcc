#include <stdlib.h>     // malloc() e free()
#include <stdio.h>      // printf() e scanf()
#include <math.h>       // log10()

int main() {
    /*
    // Sem alocacao dinamica
    int x;

    printf("Digite um valor para x: ");
    scanf("%d", &x);

    printf("O logaritmo de %d eh %f\n", x, log10(x));
    */

    // Com alocacao dinamica
    // 1. Chama malloc passando o operador sizeof() para calcular o tamanho
    //    EM BYTES do bloco de memoria a ser reservado
    // 2. malloc() devolve o endereco desse bloco na forma de um ponteiro
    //    "Generico" (void*) - precisa fazer cast para o tipo correto de
    //    ponteiro
    // 3. Salva esse endereco em um ponteiro do tipo desejado, mas (CUIDADO!)
    //    nao deve mais perder esse valor de endereco ateh libera-lo
    int* px = (int*) malloc(sizeof(int)); // macete: 3x 'int' nessa linha!

    // A partir de agora, uso a area de memoria atraves do ponteiro como
    // se eu tivesse recebido o endereco de uma variavel e guardado nesse
    // ponteiro
    printf("Digite um valor para x: ");
    scanf("%d", /*&x*/ px); // passo para scanf() o endereco de um inteiro!
                            // aqui nao existe o & na frente (ja eh endereco!)

    printf("O logaritmo de %d eh %f\n", *px, log10(*px));

    // CUIDADO! Nao pode sair do programa sem liberar a memoria alocada
    // por malloc()
    free(px);

    return 0;
}
