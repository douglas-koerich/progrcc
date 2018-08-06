#include <stdio.h>

void troca(int *, int *);

int main(void) {
	int x, y;
	int *a, *b;
	// int x, y, *a, *b;
	printf("Digite x: "); scanf("%d", &x);
	printf("Digite y: "); scanf("%d", &y);
	a = &x;
	b = &y;
	troca(a, b);
	// troca(&x, &y);
	printf("Valores trocados: x = %d, y = %d.\n", x, y);
	return 0;
}

void troca(int *a, int *b) {
	int aux;
	printf("Recebi x = %d, y = %d.\n", *a, *b);
	aux = *a;
	*a = *b;
	*b = aux;
	printf("Troquei! x = %d, y = %d.\n", *a, *b);
}
