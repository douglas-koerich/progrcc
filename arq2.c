#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_STRING	1000

int main(int argc, char* argv[]) {
	FILE* arquivo;
	char string[MAX_STRING];
	size_t tamanho;

	if (argc < 2) {
		puts("Numero invalido de parametros");
		printf("Uso: %s <nome-arquivo-saida>\n", argv[0]);
		return -1;
	}
	arquivo = fopen(argv[1], "wt");
	if (arquivo == NULL) {
		perror("Nao pude criar o arquivo");
		return -1;
	}
	do {
		__fpurge(stdin);	// limpa o teclado entre leituras de strings
		gets(string);
		tamanho = strlen(string);
		if (tamanho > 0) {
			/*
			int i = 0;
			while (string[i] != '\0') {
				if (fputc(string[i], arquivo) == EOF) { // erro?
					perror("Nao pude escrever no arquivo");
					return -1;
				}
				fflush(arquivo);	// FORCA o caracter a ser escrito
									// fisicamente (sair do buffer do S.O.)
				++i;
			}
			*/
			fputs(string, arquivo);
			fputc('\n', arquivo);	// nao se escreve o terminador nulo!
									// Ao contrario de puts(), fputs() NAO
									// escreve um \n no final
		}
	} while (tamanho > 0);

	fclose(arquivo);

	return 0;
}

