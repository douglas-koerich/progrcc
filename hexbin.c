#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		puts("Numero invalido de parametros!");
		printf("Use: %s <arq-entrada> <arq-saida>\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE* arqin = fopen(argv[1], "rb");
	if (arqin == NULL) {
		perror("Nao pude abrir arquivo:");
		return EXIT_FAILURE;
	}
	FILE* arqout = fopen(argv[2], "w");
	if (arqout == NULL) {
		perror("Nao pude criar arquivo:");
		return EXIT_FAILURE;
	}
	int contador = 0;
	while (!feof(arqin)) {
		unsigned char byte;
		if (fread(&byte, sizeof(unsigned char), 1, arqin) < 1) {
			if (ferror(arqin)) {
				perror("Nao pude ler do arquivo:");
				return EXIT_FAILURE;
			}
		}
		else {
			if (fprintf(arqout, "%02x ", byte) < 0) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
			else {
				if (++contador >= 16) {
					if (fputc('\n', arqout) == EOF) {
						perror("Nao pude escrever no arquivo:");
						return EXIT_FAILURE;
					}
					contador = 0;
				}
			}
		}
	}
	if (fclose(arqin) == EOF || fclose(arqout) == EOF) {
		perror("Nao pude fechar arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

