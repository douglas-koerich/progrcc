#include <stdlib.h>
#include <stdio.h>

int main() {
    /*
    int x = 10; // 1a. forma de carga da variavel: inicializacao
    int w, y, z;

    w = x; // 2a. forma: atribuicao (copia) a partir de uma constante
           // ou de outra variavel (como nessa linha)

    printf("Digite o valor para a variavel y: ");
    scanf("%d", &y); // 3a. forma: leitura do teclado

    z = x + y; // 4a. forma: atribuicao a partir de uma operacao (ou funcao)

    printf("O valor de x eh %d\n", x);
    printf("O valor de y eh %d e o de z eh %d\n", y, z);
    printf("O valor de w eh %d\n", w);

    float f; // Declaracao pode ser adiada ateh a primeira referencia no
             // codigo do programa

    printf("Digite o valor aproximado de PI: ");
    scanf("%f", &f);
    printf("O valor de PI eh %f\n", f);

    int i = f; // Eh possivel inicializar uma variavel com o valor de outra
    printf("A copia de PI eh %d\n", i);
    */

    short s;
    printf("Digite um valor para s: ");
    scanf("%hd", &s);
    printf("O valor de s eh %hd\n", s);
    unsigned short u = s;
    printf("O valor de u eh %hu\n", u);

    char letra;
    printf("Digite uma letra: ");
    scanf(" %c", &letra);
    printf("Voce digitou a letra %c, obrigado!\n", letra);
    int v = letra;
    printf("O valor de v eh %d\n", v);

    return EXIT_SUCCESS;
}

