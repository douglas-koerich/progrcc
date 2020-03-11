#include <stdbool.h> // definicao do tipo 'bool' importado de C++
#include <stdlib.h> // definicao de EXIT_SUCCESS retornado pelo programa
#include <stdio.h> // para uso das funcoes de E/S (escrita/leitura do console)

int main() {
    printf("O ano em que estamos eh 2020\n"); // constante texto
    printf("O ano passado era %d\n", 2019); // constante inteira

    // Imprime uma constante decimal na forma hexadecimal
    printf("A minha idade, %d, em hexadecimal eh %#x\n", 48, 48);
    // O contrario tambem eh possivel
    printf("O numero 22h (hexa) em decimal eh %d\n", 0x22);

    // Imprimindo constantes octais e binarias
    printf("O numero %d em octal eh %o\n", 011, 0b1001);

    return EXIT_SUCCESS; // return 0;
}

