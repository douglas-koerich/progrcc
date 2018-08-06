#include <stdio.h>	// estrutura FILE usada para arquivos
#ifndef WIN32
#include <stdio_ext.h>
#endif
#include <ctype.h>
#include <string.h>

#define MAX_NOME	60
#define MAX_STRING	100

int main() {
	char c, nome_arquivo[MAX_NOME], string[MAX_STRING+1];
	FILE* arq;

	puts("Digite o nome do arquivo que deseja criar:");
	gets(nome_arquivo);

	// Criar um arquivo
	arq = fopen(nome_arquivo, "w");
	if (arq == NULL) {
		perror("Erro ao criar arquivo");
		return -1;
	}
	/*
	// Escreve no arquivo cada caracter alfabetico lido do teclado
	do {
		printf("Digite caracter: ");
		scanf(" %c", &c);
		if (isalpha(c)) {
			if (fputc(c, arq) == EOF) {
				puts("Erro ao escrever no arquivo.");
				fclose(arq);
				return -1;
			}
		}
	} while (c != '#');
	if (fputc('\n', arq) == EOF) {
		puts("Erro ao finalizar arquivo.");
		fclose(arq);
		return -1;
	}
	*/
	// Escreve no arquivo cada string lida do teclado ate que seja vazia
	do {
		puts("Digite uma string:");
#ifdef WIN32
		fflush(stdin);
#else
		__fpurge(stdin);
#endif
		gets(string);
		if (strlen(string) > 0) {
			if (fputs(string, arq) == EOF) {
				perror("Erro ao escrever no arquivo");
				fclose(arq);
				return -1;
			}
			if (fputc('\n', arq) == EOF) { // fputs nao poe \n (como o puts)
				perror("Erro ao finalizar string no arquivo");
				fclose(arq);
				return -1;
			}
		}
	} while (strlen(string) > 0);

	fclose(arq);
	return 0;
}

