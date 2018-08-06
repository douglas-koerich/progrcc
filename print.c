#include <stdlib.h>
#include <stdio.h>

int main() {
    // Constantes dos diferentes tipos vistos ha pouco

    // Imprimindo a mesma constante inteira 140 em diferentes formatos (bases)
    printf("Exemplo de constante inteira: %d\n", 140); // \n separa pra nova linha
    printf("O mesmo valor, na base octal: %o; e hexadecimal: %x\n", 140, 140); // 0214 e 0x8c
    printf("Imprimindo no sentido contrario da conversao de base: %d e %d\n", 0214, 0x8c);
    printf("Mais uma conversao: %d\n", 0b10001100);

    // Imprimindo constantes reais
    printf("PI = %f\n", 3.1416);
    printf("g (na superficie da Terra) = %.1f\n", 9.81);    // com 1 casa apos a virgula
    printf("PI arredondado: %.4f\n", 3.14159265354);
    printf("c = %f\n", 2.99999714E+8);   // constante em notacao cientifica
    printf("c = %e\n", 299999714.0);

    // Imprime simbolos
    printf("Alguns simbolos: %c %c %c %c %c", 'A', '3', '@', '\x33', '\n'); // ganhei um salto de linha de gracao

    return EXIT_SUCCESS;
}
