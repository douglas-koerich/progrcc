#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Digite um numero: ");
    int n;
    scanf("%d", &n);

    // Versao simples
    char par = n % 2 == 0? 'S': 'N';

    // Executa um bloco ou outro (o que eh devolvido fica como expressao de fim do bloco)
    par = n % 2 == 0? ({ printf("Vou devolver S!\n"); 'S'; }): ({ printf("Vou devolver N!\n"); 'N'; });

    printf("O numero eh par? %c\n", par);

    // Usando o operador ternario para decidir o que imprimir...
    printf("O numero eh %s.\n", n%2==0? "Par": "Impar");

    return EXIT_SUCCESS;
}

