#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 10

int main(void) {
	int vetor[TAMANHO];
	int i;
	char c;
	int* p = vetor;
	
	for (i = 0, c = 'A'; i < TAMANHO; ++i, ++c, ++p) {
		*p = c;
		printf("%d ", vetor[i]);
	}
	putchar('\n');

	return EXIT_SUCCESS;
}