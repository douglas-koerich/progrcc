#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_FRASE	100

int main(void) {
	char frase[MAX_FRASE+1];
	puts("Digite uma frase para conversao: ");
	gets(frase);

	// String de saida: Alocacao ESTATICA com tamanho justo
	// para a string (baseado no tamanho da string de entrada)
	// char convertida[strlen(frase)+1];	// +1 para o '\0'

	// Ao inves de declarar um vetor-string, vou reservar
	// uma area de memoria que EU verei como um vetor-string
	char* convertida;
	convertida = (char*) malloc((strlen(frase)+1)*sizeof(char));
	if (convertida == NULL) {
		puts("Puts, you're in trouble!");
		return EXIT_FAILURE;
	}
	int i = 0;
	do {
		char ch = frase[i];
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
	} while (frase[i++] != '\0');

	puts("A frase convertida eh:");
	puts(convertida);

	// Depois de usar a memoria reservada, pode libera-la
	free(convertida);

	return EXIT_SUCCESS;
}

