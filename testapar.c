/*
inicio
    declare numero : inteiro
    leia numero
    se resto(numero, 2) = 0 entao
        escreva "O numero eh par"
    senao
        escreva "O numero eh impar"
    fim-se
fim
*/

// Agora segue o codigo-fonte em C equivalente ao pseudo-codigo
// acima

#include <stdio.h>
// inicio
int main() {
    // declare numero : inteiro
    int numero;
    // leia numero
    printf("Digite um numero: ");
    scanf("%d", &numero);
    // se resto(numero, 2 = 0 entao
    if (numero % 2 == 0) {
        // escreva "O numero eh par"
        printf("O numero eh par\n");
    // senao
    } else {
        // escreva "O numero eh impar"
        printf("O numero eh impar\n");
    // fim-se
    }
    return 0;
}




