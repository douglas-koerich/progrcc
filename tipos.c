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
    
    // Imprimindo um numero inteiro sem sinal
    printf("Um numero positivo: %u\n", 1453);

    // Imprimindo erroneamente um numero negativo usando %u
    printf("Um numero negativo: %d, %u\n", -12345678, -12345678);

    printf("O numero PI: %f\n", 3.14159275359); // float
    printf("O numero PI: %lf\n", 3.14159275359); // double

    printf("O numero PI: %.4f\n", 3.14159275359);
    printf("O min. Guedes diz que o dolar chega a R$ %.2f\n", 5.0);

    printf("Um numero real em notacao cientifica: %e\n", 123.456);

    printf("A primeira letra do alfabeto eh %c\n", 'A'); // cte. entre aspas simples
    printf("O codigo ASCII da primeira letra do alfabeto eh %d\n", 'A'); // printf vai pegar o codigo
    printf("O caractere cujo codigo eh %d eh %c\n", 93, 93);

    printf("Constantes logicas: %d e %d\n", false, true);

    // Tamanhos dos tipos
    printf("char = %zu\n", sizeof(char)); // sizeof() devolve o tamanho do char
    printf("short = %zu\n", sizeof(short));
    printf("long = %zu\n", sizeof(long));
    printf("long long = %zu\n", sizeof(long long));
    printf("int = %zu\n", sizeof(int));
    printf("float = %zu\n", sizeof(float));
    printf("double = %zu\n", sizeof(double));
    printf("bool = %zu\n", sizeof(bool));

    return EXIT_SUCCESS; // return 0;
}

