#include <stdio.h>

int main() {
	char string[] = "Meu primeiro arquivo escrito por um programa em C.\n";

	FILE* stream = fopen("/tmp/teste/escrito.txt", "wt");
	if (stream == NULL) {	// houve algum erro na operacao fopen()?
		perror("Nao pude criar o arquivo");
		return -1;
	}
	int i=0;
	while (string[i] != '\0') {
		char c = string[i];

		// Escreve o caracter da vez (c) no arquivo (stream), verificando
		// se houve erro de escrita
		if (fputc(c, stream) == EOF) {
			perror("Erro na escrita do caracter no arquivo");
			fclose(stream);	// nao deixe o arquivo aberto!
			return -1;
		}
		++i;
	}

	// Ao inves de escrever caracter por caracter da string, sendo uma string
	// posso escreve-la toda de uma vez
	if (fputs(string, stream) == EOF) {
		perror("Erro na escrita da string no arquivo");
		fclose(stream);
		return -1;
	}
	fclose(stream);
	return 0;
}

