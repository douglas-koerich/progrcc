#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int x;

    x = 33; // atribuicao de constante a variavel

    int y, z; // pode-se declarar mais de uma variavel do mesmo tipo
    int w = -1; // inicializacao de variavel ("nasce" com o valor -1)

    y = x; // atribuicao de variavel a variavel

    z = x + y; // atribuicao do resultado de um processamento

    printf("O conteudo da variavel x eh %d\n", x);
    printf("y e z tem, respectivamente, %d e %d\n", y, z);

    printf("O valor em w eh %d\n", w);

    char c;
    float f;

    c = x; // atribuicao de uma variavel int para outra char
    printf("O caractere na variavel c eh '%c'\n", c);

    f = x; // atribuicao de uma variavel int para outra float
    printf("O numero real em f eh %f\n", f);

    float e = 2.718281828;
    w = e; // CUIDADO! atribuicao de um float para um int
    printf("O numero real original eh %.0f\n", e);
    printf("O numero inteiro em w eh %d\n", w);
    
    float maior = ceilf(e);
    w = maior;
    printf("Usando a funcao ceilf como apoio, w = %d\n", w);

    // Entrada de valores para as variaveis
    printf("Digite um valor para x: ");
    scanf("%d", &x); // nao esqueca do & antes do nome da variavel

    printf("Digite um valor para c: ");
    scanf(" %c", &c);

    printf("Digite um valor para f: ");
    scanf("%f", &f);

    printf("c = '%c', x = %d, f = %f\n", c, x, f);

    return EXIT_SUCCESS;
}

