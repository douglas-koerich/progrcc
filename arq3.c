#include <stdio.h>
#include <string.h>

#define MAX_STRING 1000

int main(int argc, char* argv[]) {
	if (argc < 2) {
		puts("Numero insuficiente de parametros");
		printf("Uso: %s <arquivo>\n", argv[0]);
		return -1;
	}
	FILE* fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Nao pude abrir o arquivo");
		return -1;
	}
	while (!feof(fp)) {
		char string[MAX_STRING];
		if (fgets(string, sizeof(string), fp) == NULL) {
			if (ferror(fp)) {
				perror("Nao pude ler nova linha do arquivo");
				return -1;
			}
		}
		else {
			if (strstr(string, "oi")) { // procura "oi" dentro da linha lida
				printf("A substring 'oi' foi achada em '%s'\n", string);
			}
		}
	}
	fclose(fp);
	return 0;
}


