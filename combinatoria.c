#include <stdlib.h>
#include <stdio.h>

/*
 * 1. Combinacao: dados n elementos, agrupe-os em conjuntos de p elementos cada. A combinacao eh o
 *    numero desses conjuntos.
 *    C(n, p) = n! / ((n-p)! p!)
 * 2. Arranjo: uma combinacao especial em que a ordem entre os p elementos importa.
 *    A(n, p) = n! / (n-p)!
 */

unsigned long long fatorial(unsigned); // "declaracao" - prototipo - da funcao fatorial
unsigned combinacao(unsigned, unsigned);
unsigned arranjo(unsigned, unsigned);

void limpa_tela(void);

int main() {
    unsigned n; // numero total de elementos
    unsigned p; // numero de elementos no grupo

    printf("Digite o numero total de elementos: ");
    scanf("%u", &n);
    printf("Digite o numero de elementos em cada grupo: ");
    scanf("%u", &p);

    // Limpa a tela antes de apresentar os valores
    limpa_tela();

    printf("Combinacao dos elementos: %u\n", combinacao(n, p));
    printf("Arranjo dos elementos: %u\n", arranjo(n, p));

    return EXIT_SUCCESS;
}

unsigned long long fatorial(unsigned num) {
    // Variaveis LOCAIS da funcao fatorial()

    // Como o fatorial tende a ser um numero muito grande, eh necessario usar
    // um tipo de variavel adequado para essa faixa de valores
    unsigned long long fat = 1;
    unsigned x;
    for (x = 1; x <= num; ++x) {
        fat *= x;
    }
    return fat;
}

unsigned combinacao(unsigned n, unsigned p) {
    if (n < p) {
        return 0;
    }
    unsigned C;
    unsigned long long fat_n, fat_n_menos_p;

    fat_n = fatorial(n);
    fat_n_menos_p = fatorial(n-p);

    C = fat_n / (fat_n_menos_p * fatorial(p));

    return C;
}

unsigned arranjo(unsigned n, unsigned p) {
    return fatorial(n) / fatorial(n-p);
}

void limpa_tela(void) {
    system("clear"); // pede ao SO para executar o comando 'clear' (em Linux; se for Windows: 'cls')
}