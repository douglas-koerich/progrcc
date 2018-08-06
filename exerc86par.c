#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		puts("Numero invalido de parametros!");
		printf("Uso: %s <frase>\n", argv[0]);
		return EXIT_FAILURE;
	}

	/*
	char frase[MAX_FRASE+1];
	puts("Digite uma frase para conversao: ");
	gets(frase);
	*/

	// Ao inves de declarar um vetor-string, vou reservar
	// uma area de memoria que EU verei como um vetor-string
	char* convertida;
	convertida = (char*) malloc((strlen(argv[1])+1)*sizeof(char));
	if (convertida == NULL) {
		puts("Puts, you're in trouble!");
		return EXIT_FAILURE;
	}
	int i = 0;
	do {
		char ch = argv[1][i];
		if (isalpha(ch)) {
			if (isupper(ch)) {
				convertida[i] = tolower(ch);
			}
			if (islower(ch)) {
				convertida[i] = toupper(ch);
			}
		}
		else {
			convertida[i] = ch;
		}
	} while (argv[1][i++] != '\0');

	puts("A frase convertida eh:");
	puts(convertida);

	// Depois de usar a memoria reservada, pode libera-la
	free(convertida);

	return EXIT_SUCCESS;
}

