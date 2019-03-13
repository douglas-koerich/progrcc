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
    float pi = 3.14, e = 2.718281828;
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

    // Atribuicoes sem problemas
    u = octal; // ambas sao unsigned
    v = pi; // ok, converte de uma precisao mais simples para uma maior

    // CUIDADO!
    u = a;
    printf("O valor de a (%d) foi copiado para u (%u).\n", a, u);
    a = e;
    printf("O valor de e (%f) foi copiado para a (%d).\n", e, a);

    char letra, algarismo;
    int numero;
    float real;

    printf("Digite uma letra: "); // prompt de entrada
    scanf("%c", &letra); // faz a leitura do caractere do teclado para a variavel
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("Digite um algarismo: ");
    scanf(" %c", &algarismo); // o espaco-em-branco elimina o \n da leitura anterior
    printf("Digite um numero com ponto decimal: ");
    scanf("%f", &real);

    printf("Os valores digitados foram: %c, %c, %d e %f.\n", letra, algarismo,
           numero, real); // se nao for quebrar o conteudo das aspas, pode
                          // continuar na linha de baixo :-)

    return EXIT_SUCCESS;
}

