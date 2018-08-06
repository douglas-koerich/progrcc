#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "lista.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		puts("Numero invalido de parametros do programa");
		printf("Uso: %s <nome-arqtexto-entrada> <nome-arqtexto-saida>\n",
			   argv[0]);
		return EXIT_FAILURE;
	}
	FILE* arqin = fopen(argv[1], "r");
	if (arqin == NULL) {
		perror("Nao pude abrir o arquivo de entrada:");
		return EXIT_FAILURE;
	}
	FILE* arqout = fopen(argv[2], "w");
	if (arqout == NULL) {
		perror("Nao pude criar o arquivo de saida:");
		return EXIT_FAILURE;
	}
	struct indice_remissivo indice;
	criaIndice(&indice);

	char chave[128] = "";
	size_t tamanho;
	puts("Digite as palavras-chaves a seguir (para sair, apenas <Enter>):");
	do {
		printf("Palavra-chave? ");
		__fpurge(stdin);
		gets(chave);
		tamanho = strlen(chave);
		if (tamanho > 0) {
			inserePalavra(&indice, chave);
		}
	} while (tamanho > 0);

	int numero = 1;
	while (!feof(arqin)) {
		char linha[16384];
		if (fgets(linha, sizeof(linha), arqin) == NULL) {
			if (ferror(arqin)) {
				perror("Nao pude ler o arquivo de entrada:");
				destroiIndice(&indice);
				return EXIT_FAILURE;
			}
		}
		else {
			const char* delim = " \f\t\n\r\"\'!@#$%&*()=+{[}]^~/?;:.>,<\\|";
			char* palavra = strtok(linha, delim);
			while (palavra != NULL) {
				insereLinha(&indice, palavra, numero);
				palavra = strtok(NULL, delim);
			}
		}
		++numero;
	}

	if (gravaIndice(&indice, arqout) == EXIT_FAILURE) {
		destroiIndice(&indice);
		return EXIT_FAILURE;
	}
	destroiIndice(&indice);

	if (fclose(arqin) == EOF) {
		perror("Nao pude fechar o arquivo de entrada:");
		return EXIT_FAILURE;
	}
	if (fclose(arqout) == EOF) {
		perror("Nao pude fechar o arquivo de saida:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

