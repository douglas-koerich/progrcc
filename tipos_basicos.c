#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Impressao de caracteres na tela: %c %c %c\n", 'A', '@', '1');
    printf("Impressao de numeros inteiros: %d %d\n", 10, -8);
    printf("Impressao de um numero inteiro na base hexadecimal: %x\n", 20);
    printf("Impressao de um numero inteiro na base octal: %o\n", 20);
    printf("Impressao de um numero real de precisao simples: %f\n", 3.14);

    // Uso de cast para "converter" de um tipo para (outro)
    printf("Impressao de um numero real sem parte fracionaria: %f\n", (float)5);
    printf("Impressao de um numero real de precisao dupla: %lf\n", 10E+100);

    printf("Soma de 2 + 6 = %d\n", 2+6);
    printf("Soma de '2'+'6' = %d\n", '2'+'6');
    printf("Codigo ASCII do simbolo @ = %d\n", '@');

    return EXIT_SUCCESS;
}
