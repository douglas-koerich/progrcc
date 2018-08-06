#include <stdio.h>

// Parametros:
// 1o.: numero de termos de Fibonacci para gerar
// 2o.: valor de limite inferior da serie
void geraFibonacci(int, unsigned);

int main() {
    unsigned num;
    int N;

    printf("Digite o limite inferior: ");
    scanf("%u", &num);
    printf("Quantos numeros de Fibonacci deve gerar? ");
    scanf("%d", &N);

    // Simplesmente chama a funcao, sem querer usar qualquer resultado
    // da mesma (que sequer existe!)
    geraFibonacci(N, num);

    return 0;
}

void geraFibonacci(int N, unsigned num) {
    unsigned n1 = 0, n2 = 1;
    int contador = 0;
    while (contador < N) {
        unsigned fib = n1 + n2;
        if (fib > num) {
            printf("%u ", fib);
            ++contador;
        }
        n1 = n2;
        n2 = fib;
    }
    printf("\n");
}

