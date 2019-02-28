#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    bool b = true;
    char c = 'a';
    int a = -1;
    unsigned u = 10;
    unsigned octal = 010; // inicializada com uma constante octal
    unsigned hexa = 0x10; // inicializada com uma constante hexadecimal
    float pi = 3.14;
    double v = 2.9992e+8;

    printf("Um texto constante\n"); // sem variaveis

    printf("A variavel 'c' contem o caractere %c\n", c); // uma variavel impressa
    printf("Os numeros inteiros sao %d e %u\n", a, u); // duas variaveis impressas

    printf("O mesmo numero sem sinal na base octal: %o\n", u);
    printf("Ainda o mesmo numero na base hexadecimal: %x\n", u);

    printf("octal = %u e hexa = %u\n", octal, hexa);

    printf("pi = %f, pi = %.1f\n", pi, pi); // %.1f --> imprime com uma casa decimal
    printf("v = %lf\n", v); // impressao convencional do numero real
    printf("v = %e\n", v); // em notacao cientifica

    return EXIT_SUCCESS;
}

