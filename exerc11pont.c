#include <stdio.h>
#include <ctype.h>

#define MAX_FRASE	50

void converte(char[*]);		// modo classico de passagem de vetor-string
void converte_p(char*);		// usando ponteiro para receber o vetor-string

int main() {
	char frase[MAX_FRASE];	// variavel-string (vetor)

	printf("Digite uma frase: ");
	fgets(frase, MAX_FRASE, stdin);	// protege o tamanho da variavel

	// Chama a funcao de conversao
	converte(frase);
	printf("Frase convertida: %s\n", frase);

	converte_p(frase);
	printf("Frase convertida (de novo): %s\n", frase);

	return 0;
}

void converte(char string[]) {
	int i=0;
	while (string[i] != '\0') {
		if (isalpha(string[i])) {	// eh uma letra?
			if (islower(string[i])) { // eh minuscula?
				string[i] = toupper(string[i]);	// converte para maiuscula
			}
			else {
				string[i] = tolower(string[i]); // converte para minuscula
			}
		}
		++i;
	}
}

void converte_p(char* string) {
	while (*string != '\0') {
		if (isalpha(*string)) {	// eh uma letra?
			if (islower(*string)) { // eh minuscula?
				*string = toupper(*string);	// converte para maiuscula
			}
			else {
				*string = tolower(*string); // converte para minuscula
			}
		}
		++string;
	}
}

