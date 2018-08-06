#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		puts("Numero invalido de parametros!");
		printf("Uso: %s <numero>\n", argv[0]);
		return EXIT_FAILURE;
	}
	int numero = atoi(argv[1]);
	if (numero < 0) {
		numero = -numero;
	}
	printf("O valor absoluto do parametro de entrada eh %d.\n", numero);
	return EXIT_SUCCESS;
}

