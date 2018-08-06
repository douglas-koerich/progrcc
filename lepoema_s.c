#include <stdio.h>
#include <ctype.h>

#define MAX_STRING	500

int main(int argc, char* argv[]) {
	FILE* stream;
	if (argc < 3) {
		puts("Numero invalido de parametros");
		printf("Use: %s <arq-entrada> <arq-saida>\n", argv[0]);
		return -1;
	}
	stream = fopen(argv[1], "rt");
	if (stream == NULL) {
		perror("Nao foi possivel abrir o arquivo");
		return -1;
	}
	FILE* saida = fopen(argv[2], "w");
	if (saida == NULL) {
		perror("Nao pude criar o arquivo");
		fclose(stream);	
		return -1;
	}
	// Laco para ler linha por linha (string por string) do arquivo,
	// ateh o seu fim
	while (!feof(stream)) {		// faca enquanto NAO fim-do-arquivo
		char string[MAX_STRING];
		if (fgets(string, MAX_STRING, stream) == NULL) { // erro ou fim?
			if (ferror(stream)) {	// retorna verdadeiro se houve erro
				perror("Nao foi possivel ler o arquivo");
				fclose(stream);
				return -1;
			}
		}
		else {	// nao; eh uma linha valida (nao vazia)
			if (fputs(string, saida) == EOF) { // deu erro?
				perror("Nao foi possivel escrever no arquivo");
				fclose(saida);
				fclose(stream);
				return -1;
			}
		}
	}
	fclose(stream);
	fclose(saida);
	return 0;
}

