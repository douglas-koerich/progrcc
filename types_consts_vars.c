/* Logica de Programacao    C       Tamanho (bytes) Exemplos
   Numerico     Inteiro     int     4 (32 bits)     -1 5 0 2020 -36 ...
                            short   2 (16 bits)
                            long*   (dep. arquit.)
                       long long    8 (64 bits)

                           signed   (com sinal)     (os mesmos de acima)
                         unsigned   (sem sinal)     0 5 2020 1048576

                Real        float   4 (32 bits)     3.1416 -1.5 1.0 6.023e+23
                            double  8 (64 bits)     10e+100

   Caractere                char    1 (8 bits)      'A' 'a' '?' '0' '9' '#' (simbolos ASCII)

                           signed   (inteiros de baixo valor)
                         unsigned

   Texto                    ----    (variavel)      "Douglas" "Tuiuti"

   Logico                   int                     ZERO (0) = falso, NAO-ZERO (1) = verdadeiro
                            Bool_
   #include <stdbool.h> --> bool     1 (8 bits)     true false                           
*/

#include <stdlib.h>
#include <stdio.h>

int main() {
    char var_c; // Declaracao de uma variavel do tipo char (valor inicial INDETERMINADO)
    int num = 10; // Declaracao com inicializacao
    float pi = 3.1416, x, e = 2.718281828;

    var_c = '9'; // NAO EH o numero 9, eh o algarismo (grafico) 9

    /*
    printf("Um programa que mostra diferentes tipos\n"); // impressao de uma constante do tipo texto
    printf("Imprimindo um char: %c\n", '@'); // impressao de uma CONSTANTE do tipo char
    printf("Imprimindo outro char: %c\n", var_c); // impressao de uma VARIAVEL do tipo char
    */

    /*
    printf("Imprimindo um inteiro: %d\n", -30); // impressao de uma constante do tipo int
    printf("Imprimindo um outro inteiro: %d\n", num); // impressao de uma variavel do tipo int

    printf("A variavel num na base hexadecimal: %x\n", num); // impressao em outra base
    printf("A mesma variavel, em octal: %o\n", num); // impressao noutra base

    printf("Imprimindo uma constante binaria, em decimal: %d\n", 0b11010);
    printf("O mesmo numero, vindo de uma constante octal: %d\n", 032);
    printf("Ainda o mesmo numero, vindo de uma constante hexadecimal: %d\n", 0x1a);
    */

    /*
    printf("Uma constante real: %.1f\n", 2.5); // imprime com apenas uma casa apos o ponto decimal
    printf("Uma variavel real: %f\n", pi); // sem especificar o numero de casas, imprime o padrao
    printf("e = %f\n", e);
    printf("e = %.10f\n", e); // repare que a "aproximacao" (desvio) tem origem na forma como se
                              // representa um real na memoria (Arquitetura de Computadores)
    */

    /*
    float avogadro = 6.023e+23; // 6.023x10^23;
    printf("Numero de avogadro: %f\n", avogadro);
    printf("Em notacao cientifica: %e\n", avogadro);

    double avogadro_d = 6.023e+23;
    printf("Numero de avogadro (D): %lf\n", avogadro_d);

    printf("Um numero impresso com %%c %c\n", 92); // usa %% pra imprimir o simbolo '%' na tela
    printf("O mesmo numero impresso com %%d %d\n", 92);
    printf("Ainda o mesmo numero, com %%f %f\n", (float) 92); // converte o valor para o tipo indicado
    */

    char caractere_lido;
    int inteiro_lido;
    float real_lido;

    printf("Digite um caractere: ");
    scanf("%c", &caractere_lido); // ATENCAO! Nao esquecer o & antes do nome da variavel no scanf
    printf("Agora, digite um numero inteiro: ");
    scanf("%d", &inteiro_lido);
    printf("Finalmente, um outro numero (com ou sem casas decimais): ");
    scanf("%f", &real_lido);

    printf("Voce digitou %c, %d e %f\n", caractere_lido, inteiro_lido, real_lido);

    return EXIT_SUCCESS;
}