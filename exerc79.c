#include <stdio.h>
#include <ctype.h>

#define TAM	50

int main() {
	char frase[TAM];	// Variavel-string

	printf("Digite uma frase: ");
	// scanf(" %s", frase);	-> problema: nao pode ler com espacos na frase!
	gets(frase);

	unsigned vogais = 0;
	int i;
	for (i = 0; frase[i] != '\0'; ++i) {	// Percorrer ateh o fim da string
		switch (toupper(frase[i])) {		// Analisa elemento a elemento da string
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				++vogais;
				break;

			default:
				;		// nao faz nada, vamos para o proximo caracter
		}
	}

	puts("Abaixo esta reproduzida a frase:\n");	// vai saltar uma linha extra
	puts(frase);
	printf("O numero de vogais eh %u.\n", vogais);

	return 0;
}
