#include <stdlib.h>
#include <stdio.h>

int main() {
    // Programa simples que leh um numero e
    // verifica se eh par ou nao
    int numero;

    printf("Digite um numero para teste: ");
    scanf("%d", &numero);

    // se resto(numero, 2) = 0 entao
    //    escreva "O numero eh par"
    // senao
    //    escreva "O numero eh impar"
    // fim-se
    
    if (numero % 2 == 0) {
        printf("O numero eh par\n");
    } else {
        printf("O numero eh impar\n");
    }
    return EXIT_SUCCESS;
}

