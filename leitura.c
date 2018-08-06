#include <stdio.h>	// estrutura FILE usada para arquivos

#define MAX_NOME	60
#define MAX_STRING	100

int main() {
	char nome_arquivo[MAX_NOME];
	FILE* arq;

	puts("Digite o nome do arquivo que deseja ler:");
	gets(nome_arquivo);

	// Criar um arquivo
	arq = fopen(nome_arquivo, "r");
	if (arq == NULL) {
		perror("Erro ao abrir arquivo");
		return -1;
	}
	/*
	// Le do arquivo enquanto nao achar o seu fim (eof = "end of file")
	while (feof(arq) == 0) {	// == falso
		char ch = fgetc(arq);
		if (ch == EOF) {
			if (ferror(arq)) {	// EOF foi retornado por um erro, nao fim
				perror("Erro ao ler o arquivo");
				fclose(arq);
				return -1;
			}
		}
		else {
			// Ecoa na tela o caracter que foi lido do arquivo
			putchar(ch);
		}
	}
	*/
	// Le do arquivo cada string ate o fim do mesmo
	while (!feof(arq)) {
		char string[MAX_STRING+1];
		if (fgets(string, sizeof(string), arq) == NULL) {
			if (ferror(arq)) {
				perror("Erro ao ler o arquivo");
				fclose(arq);
				return -1;
			}
		}
		else {
			// Ecoa na tela a string lida do arquivo
			printf("%s", string);	// puts(string) poe um \n adicional...
		}
	}
	fclose(arq);
	return 0;
}

