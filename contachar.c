#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINHA	2000

int main(int argc, char* argv[]) {
	if (argc != 3) {
		puts("Numero invalido de parametros!");
		printf("Use: %s <nome-do-arquivo-de-entrada> <nome-do-arquivo-de-saida>\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE* arqin = fopen(argv[1], "r");
	if (arqin == NULL) {
		perror("Nao pude abrir o arquivo:");
		return EXIT_FAILURE;
	}
	FILE* arqout = fopen(argv[2], "w");
	if (arqout == NULL) {
		perror("Nao pude criar o arquivo:");
		return EXIT_FAILURE;
	}
	while (!feof(arqin)) {
		char linha[MAX_LINHA];	// vai ler linha por linha
		if (fgets(linha, sizeof(linha), arqin) == NULL) {	// erro ou fim
			if (ferror(arqin)) {	// parou porque deu erro...
				perror("Nao pude ler o arquivo:");
				return EXIT_FAILURE;
			}
		}
		else {	// nao leu EOF, entao a string/linha eh valida
			int tamanho = strlen(linha);
			if (fprintf(arqout, "%03d %s", tamanho, linha) < 0) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
		}
	}

	if (fclose(arqin) == EOF) {	// eh errado usar fclose(nome)!
		perror("Nao pude fechar o arquivo:");
		return EXIT_FAILURE;
	}
	if (fclose(arqout) == EOF) {	// eh errado usar fclose(nome)!
		perror("Nao pude fechar o arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

