#include <stdio.h>
#include <stdlib.h>

/* Este eh o esqueleto
 * basico de um programa em C. Note que este comentario
 * soh pode ser feito assim porque estou usando a forma antiga */

int main() { // Aqui comeca o programa
	// Estou terminando o programa com indicacao de sucesso
	int a;
	char b;
	float c;

	a = 65;
	b = 65;
	c = 65;

	printf("a = %d, b = %c, c = %f\n", a, b, c);

	return EXIT_SUCCESS;
}

