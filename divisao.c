#include <stdlib.h>
#include <stdio.h>

/* Operadores relacionais (de comparacao)
 * > (maior)
 * < (menor)
 * >=
 * <=
 * == (igualdade)
 * != (diferenca = nao-igualdade)
 */

int main() {
    int x, y, z = 0;

    printf("Digite um primeiro valor: ");
    scanf("%d", &x);
    printf("Digite um outro valor: ");
    scanf("%d", &y);

/*
    // Se o valor de y nao for zero, pode dividir
    if (y != 0) { // Forma alternativa: if (y) { ... }
        // Bloco de codigo executado se y for diferente de 0
        z = x / y;
        printf("A divisao (inteira) do primeiro pelo segundo resulta %d\n", z);
    } else {
        printf("Nao eh possivel dividir por ZERO!\n");
    }
*/
    if (y == 0) { // Forma alternativa: if (!y) { ... }
        printf("Nao eh possivel dividir por ZERO!\n");
    } else {
        z = x / y;
        printf("A divisao (inteira) do primeiro pelo segundo resulta %d\n", z);
    }

    return EXIT_SUCCESS;
}
