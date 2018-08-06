#include <stdio.h>

void preenche(int*, char*);

int main() {
	int x = 10;
	char y = 'a';

	printf("O valor de x eh %d e de y eh %c.\n", x, y);
	preenche(&x, &y);
	printf("O valor de x eh %d e de y eh %c.\n", x, y);

	return 0;
}

void preenche(int* a, char* b) {
	printf("Digite o valor da variavel inteira: ");
	scanf("%d", a);		// SEM o &, porque a jah eh o endereco do destino
	printf("Agora, digite o simbolo da variavel caractere: ");
	scanf(" %c", b);	// idem

	printf("O valor apontado por a (%p) eh %d e o apontado por b (%p) eh %c.\n", a, *a, b, *b);
}

