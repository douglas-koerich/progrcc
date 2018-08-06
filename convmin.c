#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_NOME	200

int main(void) {
	char nome[MAX_NOME+1];

	puts("Digite o nome do arquivo-texto para ler:");
	gets(nome);

	FILE* arquivo = fopen(nome, "r");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo:");	// mostra o erro
		return EXIT_FAILURE;
	}
	while (!feof(arquivo)) {	// enquanto fim-de-arquivo NAO(!) sinalizado
		char letra = fgetc(arquivo);
		if (letra == EOF) {	// encontrou fim ou deu erro!
			if (ferror(arquivo)) {	// parou porque deu erro...
				perror("Nao pude ler o arquivo:");
				return EXIT_FAILURE;
			}
		}
		else {	// nao leu EOF, entao eh um caracter valido
			char minusc = tolower(letra);
			putchar(minusc);
		}
	}

	if (fclose(arquivo) == EOF) {	// eh errado usar fclose(nome)!
		perror("Nao pude fechar o arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

