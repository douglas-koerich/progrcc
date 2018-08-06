#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
	FILE* f = fopen("/tmp/bruninha.txt", "r");
	if (f == NULL) {
		perror("Nao pude abrir o arquivo");
		return EXIT_FAILURE;
	}
	while (!feof(f)) {
		char string[2000];
		// Ao inves de retornar EOF se houve erro na leitura de uma nova
		// linha ou encontrou o fim do arquivo, fgets retorna NULL
		if (fgets(string, sizeof(string) /*2000*/, f) != NULL) {
			char c = toupper(string[0]);	// primeira letra da string lida
			switch (c) {
				case 'A': case 'E': case 'I': case 'O': case 'U':
					printf(string);	// puts() coloca um \n a mais do que
									// aquele que vem naturalmente do arquivo
					break;

				default:
					// nao faz nada
					;	// (comando vazio!)
			}
		}
		else if (ferror(f)) {
			perror("Nao pude ler do arquivo");
			fclose(f);
			return EXIT_FAILURE;
		}
	}
	fclose(f);
	return EXIT_SUCCESS;
}
