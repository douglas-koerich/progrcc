#include <stdlib.h>
#include <stdio.h>

int main() {
	// Declaracao de algumas variaveis: <tipo> <nome>
	char c;	// posicao de memoria com 1 byte de tamanho rotulada de c
			// com valor INDETERMINADO ("lixo")
	char C;	// OUTRA variavel, pois C faz distincao de caso (maius/minus)
	char a, b;	// duas variaveis do mesmo tipo

	int x = 0, x1 = 0;	// como nao especifiquei, eh um /signed long int/
	unsigned y;
	long z = 1;	// inicializacao: o valor inicial eh DETERMINADO!

	float f;

	// Atribuicao de valores a variaveis
	// c <- 'A'
	c = 'A';	// de constante para variavel
	x = 10;

	C = c;		// de variavel para variavel
	x1 = x;

	a = b = C;	// copia C para as duas variaveis a e b

	f = 3.14F;	// armazena a constante float

	// Quero imprimir o valor armazenado em f
	printf("f = %.3f\n", f);	// .3 indica impressao com 2 casas depois do PONTO decimal

	// Vou imprimir os caracteres que estao em a e b, mais uma constante
	printf("a = %c, b = %c, cte. = %c\n", a, b, '@');

	printf("x = %d (em hexa = %x), y = %u\n", x, x, y);

	z = 20;

	// Conversoes IMPLICITAS de tipos
	y = 3.99999;	// o valor real eh TRUNCADO para o inteiro mais baixo (3)
	b = 65;		// armazena o valor do codigo ASCII
	f = 1;		// armazena o valor 1.0F

	// Conversao EXPLICITA de tipo
	z = (long) C;	// Casting: C vai ser "visto" como um long para copiar para z

	// Leitura de valores do teclado para as variaveis
	printf("Digite o valor de a: ");
	scanf("%c", &a);

	printf("Digite o valor de x: ");
	scanf("%d", &x);

	printf("Digite o valor de b: ");
	scanf(" %c", &b);

	printf("a = %c, x = %d, b = %c\n", a, x, b);

	return EXIT_SUCCESS;
}

