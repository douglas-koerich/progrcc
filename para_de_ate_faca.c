#include <stdlib.h>
#include <stdio.h>

/* Escreva um programa que leia dois numeros, x e y, e mostre todos os numeros
 * impares nos intervalos [x, y] (inclui y) e [x, y) (exclui y) */

int main() {
    int x, y;
    do {
        printf("Digite o valor de x: ");
        scanf("%d", &x);
        printf("Digite o valor de y: ");
        scanf("%d", &y);
        if (x >= y) {
            printf("Seus numeros sao invalidos, necessario informar novamente...\n");
        }
    } while (x >= y);   // garante que as entradas sao validas (na ordem crescente)

    // Impressao para [x, y]
    // para i de x ate y passo 1 faca
    int i;
    for (i = x; i <= y; ++i) {
        // se resto(i, 2) = 1 entao
        if (i % 2 == 1) {
            // escreva i
            printf("%d ", i);
        // fim-se
        }
    // fim-para
    }
    printf("\n");   // salto de linha pra terminar o programa

    // Impressao para [x, y)
    for (i = x; i < y; ++i) {   // soh entra no laco se i for MENOR (mas NAO IGUAL como acima)
        if (i % 2) {    // resultado soh pode ser 0 (que eh visto como falso) ou 1 (que eh visto como verdadeiro)
            printf("%d ", i);
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}
