#include <stdlib.h>
#include <stdio.h>

void troca(int* a, int* b) {
	printf("Antes da troca: a = %d, b = %d\n", *a, *b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Depois da troca: a = %d, b = %d\n", *a, *b);
}

int main(void) {
	int x;
	x = 10;
	/*
	printf("O valor de x eh %d\n", x);

	int* p = NULL; // inicializa o ponteiro com um endereco intencionalmente INVALIDO

	p = &x; // operador de referencia ("o endereco de...")
	printf("O endereco da variavel x eh %p\n", p);

	printf("Digite um NOVO valor de x: ");
	scanf("%d", p); // SEM o & na frente, porque senao guardaria o valor na propria variavel p

	// printf("x agora vale %d\n", x);
	printf("x agora vale %d\n", *p); // operador de indirecao ("o conteudo armazenado em...")
	*/
	int y = 5;
	printf("Antes da troca: x = %d, y = %d\n", x, y);
	troca(&x, &y);
	printf("Depois da troca: x = %d, y = %d\n", x, y);

	return EXIT_SUCCESS;
}