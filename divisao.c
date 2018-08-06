#include <stdlib.h>
#include <stdio.h>

// inicio
int main() {
    // declare dividendo, divisor, quociente : inteiro
    int dividendo, divisor, quociente;

    // leia dividendo, divisor
    printf("Digite o valor a ser dividido: ");
    scanf("%d", &dividendo);
    printf("Digite o valor que divide: ");
    scanf("%d", &divisor);

    // se divisor <> 0 entao
    if (divisor != 0) {     // { <=> "entao"
    /*
    if (divisor) {  // valor de divisor igual a 0 eh visto como falso;
                    // se diferente de 0, eh visto como verdadeiro
    */
        // quociente <- dividendo / divisor
        quociente = dividendo / divisor;

        // escreva quociente
        printf("O resultado da divisao eh %d\n", quociente);
    // fim-se   ; nao faz nada se divisor for nulo
    }
    return EXIT_SUCCESS;

// fim
}
