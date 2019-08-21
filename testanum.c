#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    /* se n >= 0 entao
     *   imprima "O numero eh positivo"
     * senao
     *   imprima "O numero eh negativo"
     * fim-se
     */
    if (n == 0) // OU if (!n)
        puts("O numero eh ZERO");
    else { // caso o numero seja diferente de zero
        if (n > 0)
            puts("O numero eh positivo");
        else { // chaves sao necessarias se ha mais de um comando no bloco alternativo
            puts("O numero eh negativo");
            puts("Numeros negativos sao feios!...");
        }
    }
    // printf("O numero digitado eh %d\n", n);

    if (n % 2 == 0 && n % 3 == 0) {
        puts("O numero eh par e divisivel por 3 tambem");
    } else { // por DeMorgan, este 'else' equivale a 'if (!(n%2==0) || !(n%3==0))'
        puts("O numero eh impar ou nao-divisivel por 3");
    }

    /* Este caso abaixo eh um erro onde a mensagem sempre serah impressa
    if (n % 5 == 0);
        puts("Eh divisivel por 5");
    */

    return EXIT_SUCCESS;
}

