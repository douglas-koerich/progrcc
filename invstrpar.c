#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		puts("Numero invalido de parametros!");
		printf("Uso: %s <palavra>\n", argv[0]);
		return EXIT_FAILURE;
	}
	char invertida[strlen(argv[1])+1];
	int i, j;
	for (i = 0, j = strlen(argv[1])-1; j >= 0; ++i, --j) {
		invertida[i] = argv[1][j];
	}
	invertida[i] = '\0';
	puts(invertida);
	return EXIT_SUCCESS;
}

