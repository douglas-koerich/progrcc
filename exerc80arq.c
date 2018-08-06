#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define	MAX	100

int main(int argc, char* argv[]) {
	if (argc < 2) {
		puts("Numero invalido de parametros");
		return -1;
	}
	FILE* arquivo = fopen(argv[1], "wt");
	if (arquivo == NULL) {
		perror("Nao pude criar o arquivo solicitado");
		return -1;
	}
	char frase[MAX];
	size_t tamanho;
	do {
		printf("Digite uma frase para criptografar: ");
		gets(frase);

		tamanho = strlen(frase);	// numero de caracteres validos
		if (tamanho > 0) {			// string nao vazia?
			int i, j;
			char cripto[tamanho+1];	// num de validos nao conta o \0
			for (i = tamanho-1, j = 0; i >= 0; --i, ++j) {
				if (!isalpha(frase[i])) {
					cripto[j] = frase[i];
				}
				else {
					switch (toupper(frase[i])) {
						case 'A': case 'E': case 'I': case 'O': case 'U':
							cripto[j] = frase[i];
							break;
			
						default:	// as consoantes
							cripto[j] = '#';
					}
				}
			}
			cripto[tamanho-1] = '\0';
			if (fputs(cripto, arquivo) == EOF) {
				perror("Nao pude escrever no arquivo criptografado");
				fclose(arquivo);
				return -1;
			}
			if (fputc('\n', arquivo) == EOF) {
				perror("Nao pude terminar a linha no arquivo");
				fclose(arquivo);
				return -1;
			}
		}
	} while (tamanho > 0);

	fclose(arquivo);
	return 0;
}
