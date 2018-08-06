#include <stdio.h>

#define LINHAS 3
#define COLUNAS 5

int main(void) {
	int matriz[LINHAS][COLUNAS] = {
		{ 1, 2, 3, 5, 7 },
		{ 0, 2, 4, 6, 8 },
		{ 7, 14, 21, 28, 35 }
	};
	// No arquivo-texto, vamos escrever a matriz de forma "diagramada"
	// (linhas x colunas)
	FILE* txt = fopen("matriz.txt", "wt");
	if (txt == NULL) {
		perror("Nao pude criar arquivo texto");
		return -1;
	}
	// Como vou escrever nos 2 arquivos na mesma passada, ambos devem estar
	// abertos simultaneamente, por isso preciso de um segundo ponteiro FILE
	FILE* bin = fopen("matriz.bin", "wb");
	if (bin == NULL) {
		perror("Nao pude criar arquivo binario");
		return -1;
	}
	int l, c;
	for (l = 0; l < LINHAS; ++l) {
		for (c = 0; c < COLUNAS; ++c) {
			fprintf(txt, "%3d ", matriz[l][c]);	// texto formatado
			
			/*
			// 1a. versao da escrita em binario: poe no arquivo numero por
			// numero (por isso o terceiro parametro eh 1)
			fwrite(&matriz[l][c], sizeof(int), 1, bin);	// binario puro
			*/
		}
		fputc('\n', txt);	// nao preciso do fprintf p/ escrever 1 char

		/*
		// 2a. versao da escrita em binario: poe TODOS os bytes de TODOS
		// os numeros dessa linha (l) de UMA SOH VEZ no arquivo
		fwrite(&matriz[l][0], sizeof(int), COLUNAS, bin);
		*/
	}
	// 3a. versao da escrita em binario: poe a matriz toda de uma vez
	fwrite(&matriz[0][0], sizeof(int), LINHAS*COLUNAS, bin);

	fclose(txt);
	fclose(bin);

	return 0;
}


