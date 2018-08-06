#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Constantes do tipo logico (booleano) : bool
    printf("verdadeiro=%d\n", true); // para imprimir logico, usa inteiro
    printf("falso=%d\n", false);
    printf("Tamanho de um bool: %zd\n", sizeof(true));

    // Constantes do tipo inteiro : int
    printf("Nosso ano corrente=%d\n", 2018);
    printf("Ano em hexadecimal=%x\n", 2018);
    printf("Ano em octal=%o\n", 2018);
    printf("Nosso saldo no jogo da copa com a Alemanha=%d\n", -6);
    printf("Tamanho de um int: %zd\n", sizeof(int));

    // Constantes do tipo inteiro sem sinal : unsigned int (ou somente unsigned)
    printf("Nosso ano corrente=%u\n", 2018U);
    printf("Tamanho de um unsigned: %zd\n", sizeof(unsigned));

    // Constantes do tipo inteiro "curto" : short int (ou somente short)
    printf("Nosso ano corrente=%hd\n", 2018);
    printf("Distancia da terra a lua [km]=%hd\n", 384400);
    printf("Tamanho de um short: %zd\n", sizeof(short));

    // Constantes do tipo real de precisao simples : float
    printf("Constante de Euler (e)=%f\n", 2.718281828459F);
    printf("Constante (e) arredondada=%.2f\n", 2.718281828459F);
    printf("Tamanho de um float: %zd\n", sizeof(float));

    // Constantes do tipo real de precisao dupla : double
    printf("Constante PI=%.8lf\n", 3.14159265359);
    printf("Constante PI em notacao cientifica=%e\n", 3.14159265359);
    printf("Constante de Avogadro: %e\n", 6.022e+23);
    printf("Tamanho de um double: %zd\n", sizeof(double));

    // Constantes do tipo caractere : char
    printf("Primeira letra do alfabeto=%c\n", 'A');
    printf("Primeiro algarismo arabico=%c\n", '0'); // nao eh 0 (sem aspas simples)!
    printf("Tamanho de um char: %zd\n", sizeof(char));

    // Constante do tipo texto : (NAO EXISTE TIPO EM C)
    printf("Minha mensagem final=%s\n", "Ate quinta-feira!");
    
    return EXIT_SUCCESS;
}
