#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	MAX	100

int main() {
	char frase[MAX];

	printf("Digite uma frase para criptografar: ");
	gets(frase);

	int tamanho = strlen(frase) + 1;	// numero de posicoes ocupadas em frase (+1 para \0)
	char cripto[tamanho];				// vetor com tamanho a partir de variavel
										// (vai ter o tamanho JUSTO para a string)

	// Para criptografar, tenho que percorrer o vetor/string original de tras para frente
	// substituindo nao-vogais (consoantes) por #
	int i, j;
	for (i = strlen(frase)-1, j = 0; i >= 0; --i, ++j) {
		if (!isalpha(frase[i])) {	// Se NAO (!) for uma letra (alphabeto)
			cripto[j] = frase[i];
		}
		else {
			switch (toupper(frase[i])) {
				case 'A': case 'E': case 'I': case 'O': case 'U':
					cripto[j] = frase[i];
					break;
	
				default:	// as consoantes
					cripto[j] = '#';
			}
		}
	}
	// Copia (ou encerra a string de destino com) o terminador nulo
	cripto[tamanho-1] = '\0';

	printf("Frase criptografada: %s\n", cripto);
	return 0;
}
