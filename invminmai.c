#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_NOME	200

int main(void) {
	char entrada[MAX_NOME+1], saida[MAX_NOME+1];

	puts("Digite o nome do arquivo-texto para ler:");
	gets(entrada);
	puts("Digite o nome do arquivo-texto para escrever:");
	gets(saida);

	FILE* arqin = fopen(entrada, "r");
	if (arqin == NULL) {
		perror("Nao pude abrir o arquivo:");
		return EXIT_FAILURE;
	}
	FILE* arqout = fopen(saida, "w");
	if (arqout == NULL) {
		perror("Nao pude criar o arquivo:");
		return EXIT_FAILURE;
	}
	while (!feof(arqin)) {
		char letra = fgetc(arqin);
		if (letra == EOF) {
			if (ferror(arqin)) {
				perror("Nao pude ler o arquivo:");
				return EXIT_FAILURE;
			}
		}
		else {
			char inv;
			if (isupper(letra)) {
				inv = tolower(letra);
			}
			else {
				inv = toupper(letra);
			}
			if (fputc(inv, arqout) == EOF) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
		}
	}

	if (fclose(arqin) == EOF || fclose(arqout) == EOF) {
		perror("Nao pude fechar o arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

