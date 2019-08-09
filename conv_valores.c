#include <stdlib.h>
#include <stdio.h>

int main() {
    float var;
    printf("Digite um numero real (com casas decimais apos o ponto): ");
    scanf("%f", &var);
    
    int inteiro = var; // inicializa um int com o valor da variavel float
    printf("O inteiro correspondente ao valor eh %d\n", inteiro);

    unsigned sem_sinal;
    sem_sinal = inteiro;
    printf("O numero sem sinal eh %u\n", sem_sinal); // %u pra unsigned!

    int milhao = 1000000;
    short valor = milhao;
    printf("O valor short eh %hd\n", valor); // %hd pra short

    printf("O valor 1000000 na base hexadecimal: %x\n", milhao);
    printf("O mesmo 1000000 na base octal: %o\n", milhao);

    int hexa = 0x12ab0;
    int octal = 05623; // nao pode ter os algarismos 8 e 9, obviamente
    int bin = 0b10011;

    printf("Na base decimal, ficam: %d, %d e %d\n", hexa, octal, bin);

    return EXIT_SUCCESS;
}

