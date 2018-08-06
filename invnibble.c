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
	FILE* arqout = fopen(argv[2], "wb");
	if (arqout == NULL) {
		perror("Nao pude criar arquivo:");
		return EXIT_FAILURE;
	}
	while (!feof(arqin)) {
		unsigned char byte;
		if (fread(&byte, sizeof(unsigned char), 1, arqin) < 1) {
			if (ferror(arqin)) {
				perror("Nao pude ler do arquivo:");
				return EXIT_FAILURE;
			}
		}
		else {
			unsigned char aux = byte & 0xf;	// E binario com 00001111
			byte = byte >> 4;	// desloca os bits de 'byte' 4 posicoes pra direita
			aux <<= 4;			// aux = aux << 4; desloca 4 posicoes pra direita
			byte = aux | byte;  // OU binario entre aaaa0000 (aux) e 0000bbbb (byte)
			if (fwrite(&byte, sizeof(unsigned char), 1, arqout) < 1) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
		}
	}
	if (fclose(arqin) == EOF || fclose(arqout) == EOF) {
		perror("Nao pude fechar arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

