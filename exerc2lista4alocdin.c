#include <stdlib.h>
#include <stdio.h>

/*
 * Elabore um procedimento em linguagem C que gere e RETORNE os 3 (tres)
 * primeiros numeros de Fibonacci maiores que um valor tambem informado por
 * parametro ao procedimento.
 */
// Parametros:
// 1o.: valor de limite inferior da serie de 3 numeros
// 2o.: endereco da primeira variavel onde o procedimento armazena o
//      o primeiro numero gerado
// 3o.: endereco da segunda variavel (para o segundo numero gerado)
// 4o.: endereco da terceira variavel (para o terceiro numero gerado)

void geraFibonacci(unsigned, unsigned*, unsigned*, unsigned*);

int main() {
    /*
    unsigned num, fib1, fib2, fib3;
    */

    // Com alocacao dinamica
    unsigned num;
    unsigned* fib = (unsigned*) malloc(3 * sizeof(unsigned));
    // aloquei um "vetor" ao inves de tres variaveis separadas...

    printf("Digite o limite inferior: ");
    scanf("%u", &num);

    // Simplesmente chama a funcao, sem querer usar qualquer resultado
    // da mesma (que sequer existe!)
    // geraFibonacci(num, &fib1, &fib2, &fib3);
    geraFibonacci(num, fib, fib+1, fib+2);  // fib = endereco do inicio do vetor (do primeiro valor)
                                            // fib+1 = endereco do seguinte (segundo valor no vetor)
                                            // fib+2 = endereco do ultimo (terceiro valor no vetor)

    // Imprime os valores gerados
    printf("%u %u %u\n", fib[0], fib[1], fib[2]);   // uso como se fosse vetor mesmo!

    // NAO ESQUECER DE LIBERAR A MEMORIA!
    free(fib);

    return 0;
}

void geraFibonacci(unsigned num, unsigned* pf1, unsigned* pf2, unsigned* pf3) {
    unsigned n1 = 0, n2 = 1;
    int contador = 1;
    while (contador <= 3) {
        unsigned fib = n1 + n2;
        if (fib > num) {
            switch (contador) {
                case 1: *pf1 = fib;
                        break;
                case 2: *pf2 = fib;
                        break;
                case 3: *pf3 = fib;
                        break;
                default:
                        return; // nao deveria chegar ateh aqui!
            }
            ++contador;
        }
        n1 = n2;
        n2 = fib;
    }
}

