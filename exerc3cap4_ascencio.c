#include <stdlib.h>
#include <stdio.h>

int main() {
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    /* Estruturas de decisao simples:
       Note que os 3 testes vao ser feitos, mesmo se o primeiro
       jah resultar verdadeiro! */
    if (num1 > num2) {
        // bloco de codigo da condicao verdadeira
        printf("O maior numero eh: %d\n", num1);
    }
    if (num2 > num1) {
        printf("O maior numero eh: %d\n", num2);
    }
    // Cuidado! Se fizer (num1 = num2), imprimira "iguais" se num2 <> 0
    if (num1 == num2) {
        printf("Os numeros sao iguais\n");
    }
    return EXIT_SUCCESS;
}
