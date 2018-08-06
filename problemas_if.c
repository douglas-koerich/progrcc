#include <stdio.h>

int main() {
	int a, b, c = -1;

	printf("Digite a: "); scanf("%d", &a);
	printf("Digite b: "); scanf("%d", &b);

	/*
	if (b != 0);	// somente ; eh o "comando vazio" (faz "nada")
	{				// passou a ser um bloco destacado dentro do proprio main (soh isso)
		c = a / b;
		printf("c = %d\n", c);
	}
	*/

	if (b = 0) {	// b passa a ser zero; zero significa "falso", por isso vai para o else
		printf("b invalido (nulo)!\n");
	}
	else {
		c = a / b;
		printf("c = %d\n", c);
	}
	return 0;
}

