#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    printf("Digite um numero para teste: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        // Escopo local da condicao verdadeira
        // (tudo o que serah executado para 'true')
        printf("O numero eh par\n");
    } else {
        // Escopo da condicao falsa
        // (o que serah executado em caso 'false')
        printf("O numero eh impar\n");
    }
    return EXIT_SUCCESS;
}

