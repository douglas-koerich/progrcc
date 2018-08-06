#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned n; // se n deve ser maior ou igual a 0, eh um numero sem sinal
    printf("Digite o numero de ordem (n): ");
    scanf("%d", &n);

    int f_n;
    if (n == 0 || n == 1) {
        f_n = n;    // f_n = 0 ou f_n = 1
    } else {    // n >= 2
        /* Pra calcular f_n, eh necessario ir calculando cada f intermediario,
           ateh chegar nos dois imediatamente anteriores. Os primeiros dois
           anteriores sao justamente f_0 e f_1 */
        int f_n_menos_2 = 0;    // primeiro penultimo
        int f_n_menos_1 = 1;    // primeiro ultimo
        int i = 2;              // numero de ordem intermediario, comeca em 2 ateh n
        do {
            f_n = f_n_menos_1 + f_n_menos_2;
            f_n_menos_2 = f_n_menos_1;  // prepara f_n_menos_2 para a proxima execucao do laco, se acontecer
            f_n_menos_1 = f_n;          // idem para f_n_menos_1
        } while (n > i++);              // repare que i eh incrementado DEPOIS da comparacao com n
    }
    printf("O numero de Fibonacci f(%d) eh %d.\n", n, f_n);

    return EXIT_SUCCESS;
}
