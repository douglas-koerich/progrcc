#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
	FILE* f = fopen("/tmp/literatura.txt", "rt");
	if (f == NULL) {
		perror("Nao pude abrir o arquivo para leitura");
		return EXIT_FAILURE;	// = -1
	}
	// Ler TODO o conteudo do arquivo
	// Isso significa REPETIR a leitura individual de caracter por
	// caracter ateh chegar o fim do arquivo
	
	/*****
	 * 1a. versao
	 *****
	char c;
	do {
		// Ler o proximo caracter/byte
		c = fgetc(f);
		if (c == EOF) {	// fim do arquivo OU erro
			if (ferror(f)) {	// houve um erro na ultima operacao?
				perror("Nao pude ler do arquivo");
				fclose(f);
				return EXIT_FAILURE;
			}
			// senao, eh fim de arquivo mesmo, nao faz nada...
		}
		else {
			c = toupper(c);	// converte o caracter para maiuscula
			putchar(c);		// imprime o caracter maiusculo na tela
		}
	} while (c != EOF);
	******
	* Fim da 1a. versao
	*****/

	/*****
	 * 2a. versao (mais comum)
	 ****/
	while (!feof(f)) {
		char c = fgetc(f);
		if (c != EOF) {
			c = toupper(c);
			putchar(c);
		}
		else if (ferror(f)) {
			perror("Nao pude ler do arquivo");
			fclose(f);
			return EXIT_FAILURE;
		}
	}

	fclose(f);
	return EXIT_SUCCESS;		// = 0
}

