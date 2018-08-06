#include <stdlib.h>
#include <stdio.h>

int main(void) {
    unsigned char c = 'A';   // para representar bytes "brutos", use unsigned char
    unsigned char x = 0x42;  // constante hexadecimal comeca com 0x
    unsigned char b = 2;     // codigo 02 na tabela ascii eh o STX
    printf("c = %c (%x)\n", c, c);
    printf("x = %d (%x) (%c)\n", x, x, x);
    printf("b = %d (%x) (%c)\n", b, b, b);

    unsigned char e = c << 1;    // desloca o padrao de bits de c uma posicao para esquerda
    printf("e = %#x\n", e);
    unsigned char d = x >> 1;
    printf("d = %#x\n", d);
    unsigned char m = x >> 4;   // desloca o padrao de x quatro bits para a direita
    printf("m = %#x\n", m);

    unsigned char n = ~c;       // inverte todos os bits de c
    printf("n = %#x\n", n);

    unsigned char y = 0x66;     // 0110 0110
    unsigned char z = 0x23;     // 0010 0011
    printf("y & z = %#x\n", y & z);
    printf("y | z = %#x\n", y | z);

    // Ligando ("setando") o bit7 de y (0x66 -> 0xE6)
    y |= (1 << 7);
    printf("y = %#x\n", y);
    // Desligando ("resetando") o bit1 de z (0x23 -> 0x21)
    z &= ~(1 << 1); // necessario inverter os bits da mascara
    printf("z = %#x\n", z);

    unsigned char p = 0x3C;
    unsigned char q = 0xA5;
    printf("p ^ q = %#x\n", p ^ q);

    if (p ^ q) {
        printf("p e q sao DIFERENTES\n");
    }
    else {
        printf("p e q sao IGUAIS\n");
    }
    p = q = 0x47;
    if (p ^ q) {
        printf("Agora, p e q sao DIFERENTES\n");
    }
    else {
        printf("Agora, p e q sao IGUAIS\n");
    }

    return EXIT_SUCCESS;
}
