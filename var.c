#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Inicializacao com constantes de mesmo tipo
    const char c = 'A'; // ou c = '\x41';
    const int i = 10; // ou i = 0xA; (ou ainda i = 0xa;) - HEXADECIMAL
                      // ou i = 012; - OCTAL
                      // ou i = 0b1010; - BINARIO
    const float f = 3.1416F;
    const double d = 3.1416;
    const bool b = true;

    // Impressao das variaveis-constantes
    printf("Variavel char: c = %c\n", c);
    printf("Variavel int: i = %d (%i)\n", i, i);   // imprime 2x a variavel i
    printf("Variavel float: f = %f\n", f);
    printf("Variavel double: d = %lf\n", d);
    printf("Variavel logica: b = %d\n", b);

    // Impressoes alternativas
    printf("Codigo numerico do char: c = %hhd\n", c);
    printf("Variavel int em octal: i = %o; em hexa: i = %x (%X)\n", i, i, i);
    printf("Variavel float com 2 casas: f = %.2f\n", f);
    printf("Variavel double em notacao cientifica: d = %e\n", d);

    // Variaveis comuns (nao constantes)
    char c1;
    c1 = c;         // copia entre variaveis
    int i1;
    i1 = -5;        // atribuicao de uma constante
    float F = f;    // inicializacao com valor de outra variavel

    // Inicializacao com constantes de outro tipo
    const char C = 200;     // alem do maior valor suportado (+127)
    const unsigned I = -10; // numero negativo atribuido a um inteiro SEM sinal
    const int J = 2.71828;  // numero real com parte fracionaria atribuido a um inteiro
    const bool B = 5;       // numero atribuido a tipo logico

    printf("C = %c (codigo %hhd)\n", C, C);
    printf("I = %u (%#x)\n", I, I); // %#x vai imprimir 0xNNNN
    printf("J = %d\n", J);
    printf("B = %d\n", B);

    // Leitura de valores para variaveis
    printf("Novo valor de i1: ");
    scanf("%d", &i1);
    printf("Novo valor de c1: ");
    scanf(" %c", &c1);      // note o uso do espaco dentro das aspas para "limpar" a entrada
    printf("Novo valor de F: ");
    scanf("%f", &F);
    printf("O valor de c1 agora eh %c, de i1 eh %d e de F eh %f\n", c1, i1, F);

    return EXIT_SUCCESS;
}

