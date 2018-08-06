#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LINHA	2000

#ifndef WIN32
void strupr(char* string) {
	while (*string != '\0') {
		*string = toupper(*string);
		++string;
	}
}
#endif

int main(int argc, char* argv[]) {
	if (argc != 2) {
		puts("Numero invalido de parametros!");
		printf("Use: %s <nome-do-arquivo>\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE* arquivo = fopen(argv[1], "r");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo:");
		return EXIT_FAILURE;
	}
	while (!feof(arquivo)) {
		char linha[MAX_LINHA];	// vai ler linha por linha
		if (fgets(linha, sizeof(linha), arquivo) == NULL) {	// erro ou fim
			if (ferror(arquivo)) {	// parou porque deu erro...
				perror("Nao pude ler o arquivo:");
				return EXIT_FAILURE;
			}
		}
		else {	// nao leu EOF, entao a string/linha eh valida
			strupr(linha);
			printf("%s", linha);	// se usar puts, vai duplicar o salto de linha
									// pois ja leu um do arquivo!
		}
	}

	if (fclose(arquivo) == EOF) {	// eh errado usar fclose(nome)!
		perror("Nao pude fechar o arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

