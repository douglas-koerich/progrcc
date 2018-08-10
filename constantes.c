#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Uma mensagem de conteudo fixo\n");
    printf("Um numero na base decimal: %d...\n", 3078);
    printf("Dois valores inteiros: %d e %d.\n", -2, +15);
    printf("Exibindo o valor decimal para 1074 que estah na base octal: %d.\n", 01074);
    printf("Exibindo o valor decimal para 1074 que estah na base hexadecimal: %d.\n", 0x1074);
    printf("Exibindo o valor decimal para 10001101 que estah em binario: %d.\n", 0b10001101);
    printf("Exibindo o valor hexadecimal para 1074 que estah agora na base decimal: %x.\n", 1074);
    printf("Exibindo o valor octal para 1074 (em decimal): %o.\n", 1074);

    printf("Um numero negativo: %d.\n", -100);
    printf("Um numero negativo impresso como se fosse sem-sinal (ERRO!): %u.\n", -100);

    printf("Algumas constantes do tipo caractere: %c, %c e %c.\n", 'A', '@', '0');
    printf("O codigo ASCII do simbolo %c eh %d.\n", 'A', 'A');

    printf("PI eh igual a %f.\n", 3.1416);
    printf("Velocidade da luz no vacuo: %lf (%e).\n", 299799.94, 299799.94);
    printf("Um erro na interpretacao do real: %.20lf\n", 2.2);

    return EXIT_SUCCESS;
}

