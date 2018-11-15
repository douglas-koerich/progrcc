#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int i = 10;
	int j, k;
	char c = 'a';

	int* pi;
	// int* pj, pk; >:-o) pk eh um inteiro
	int *pj, *pk; // pj e pk sao ponteiros
	char* pc;

	// Ponteiro que guarda o endereco da variavel 'i'
	pi = &i;

	// Ponteiro que guarda o endereco em memoria da variavel 'c'
	pc = &c;

	printf("i = %d\n", i);
	printf("c = %c\n", c);

	printf("pc = %p\n", pc);
	printf("pi = %p\n", pi);

	printf("i = %d\n", *pi);
	printf("c = %c\n", *pc);

	pc = pi;

	*pi = 20;
	*pc = 'b';

	printf("i = %d\n", i);
	printf("c = %c\n", c);

	system("pause");

	return EXIT_SUCCESS;
}
