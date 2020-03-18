#include <stdlib.h>
#include <stdio.h>
#include <math.h> // essa biblioteca pede o uso de "-lm" na linha do gcc

/* Identificar o algarismo mais significativo de um numero inteiro
 * passa pela deducao de qual eh a sua grandeza (centena, milhar,
 * milhao, etc.).
 * Eh ai que entra o logaritmo, que como voce deve lembrar da
 * matematica do Ensino Medio, calcula o *expoente* de uma base
 * que resultou no numero em questao. Esse expoente eh uma forma
 * de quantificar a grandeza do numero.
 * Por exemplo, o logaritmo (da base 10) do numero 257 eh 2.41; jah
 * o logaritmo de 251087 eh 5.40. Note que a parte inteira do logaritmo
 * eh igual ao numero de algarismos menos um ;-)
 * Sabendo quantos algarismos um numero tem, podemos extrair o mais
 * significativo dividindo-o pela maior potencia (pow!) de 10 que
 * seja menor que ele.
 */

int main() {
    unsigned N; // enunciado: "... um inteiro positivo... "

    printf("Digite um numero inteiro positivo: ");
    scanf("%u", &N); // %u eh para inteiros sem sinal, lembra-se?

    // Note que a funcao log10 retorna um 'double', mas ao copiar
    // esse valor para uma variavel 'int', apenas a parte inteira
    // eh armazenada
    int algarismos = log10(N) + 1; // deduz o no. de algarismos do log

    // Calcula a maior potencia de 10 com esse numero de algarismos
    int potencia_10 = pow(10, algarismos - 1); // expoente eh o no. de zeros
                                               // dessa potencia

    // Agora, obter o algarismo mais significativo eh um procedimento
    // semelhante ao que foi feito no exercicio 1, "decompondo" o
    // numero original
    int mais_signficativo = N / potencia_10;

    printf("O algarismo mais significativo de %u eh %d\n", N,
           mais_signficativo);

    return EXIT_SUCCESS;
}

