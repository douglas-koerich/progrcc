#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_STRING	1000

int main(int argc, char* argv[]) {
	if (argc < 3) {
		puts("Numero invalido de parametros");
		printf("Use: %s <arq-original> <arq-copia>\n", argv[0]);
		return -1;
	}
	FILE* original = fopen(argv[1], "wt");
	if (original == NULL) {
		perror("Nao pude criar arquivo original");
		return -1;
	}
	char string[MAX_STRING];
	do {
		printf("Digite nova string: ");
		__fpurge(stdin);
		gets(string);
		if (string[0] != '\0') {
			strcat(string, "\n");
			if (fputs(string, original) == EOF) {
				perror("Nao pude escrever no arquivo original");
				fclose(original);
				return -1;
			}
		}
	} while (strlen(string) > 0);
	fclose(original);

	FILE* copia = fopen(argv[2], "wt");
	if (copia == NULL) {
		perror("Nao pude criar arquivo de copia");
		return -1;
	}
	original = fopen(argv[1], "rt");
	if (original == NULL) {
		perror("Nao pude abrir arquivo original");
		fclose(copia);
		return -1;
	}
	while (!feof(original)) {
		if (fgets(string, sizeof(string), original) == NULL) {
			if (ferror(original)) {
				perror("Nao pude ler do arquivo original");
				fclose(original);
				fclose(copia);
				return -1;
			}
		}
		else {
			if (fputs(string, copia) == EOF) {
				perror("Nao pude escrever no arquivo de copia");
				fclose(original);
				fclose(copia);
				return -1;
			}
		}
	}
	fclose(original);
	fclose(copia);
	return 0;
}

