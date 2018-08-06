#include <stdio.h>

#define LINHAS 5
#define COLUNAS 3

int main(void) {
	int matriz[LINHAS][COLUNAS];
	int l, c;

	FILE* txt = fopen("matriz.txt", "rt");
	if (txt == NULL) {
		perror("Nao pude abrir o arquivo texto");
		return -1;
	}
	for (l = 0; l < LINHAS; ++l) {
		for (c = 0; c < COLUNAS; ++c) {
			fscanf(txt, "%d", &matriz[l][c]);
		}
	}
	fclose(txt);

	for (l = 0; l < LINHAS; ++l) {
		putchar('|');
		for (c = 0; c < COLUNAS; ++c) {
			printf("%3d |", matriz[l][c]);
		}
		putchar('\n');
	}
	FILE* bin = fopen("matriz.bin", "rb");
	if (bin == NULL) {
		perror("Nao pude abrir o arquivo binario");
		return -1;
	}
	int matriz2[LINHAS][COLUNAS];
	for (l = 0; l < LINHAS; ++l) {
		// Le todos os 3 numeros da coluna de uma soh vez
		fread(&matriz2[l][0], sizeof(int), COLUNAS, bin);
	}
	fclose(bin);
	for (l = 0; l < LINHAS; ++l) {
		putchar('!');
		for (c = 0; c < COLUNAS; ++c) {
			printf("%3d !", matriz[l][c]);
		}
		putchar('\n');
	}
	return 0;
}

