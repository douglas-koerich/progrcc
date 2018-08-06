#include <stdio.h>

#define LINHAS 5
#define COLUNAS 3

int main() {
	char nome_arquivo[100];
	printf("Digite o nome do arquivo para leitura: ");
	gets(nome_arquivo);

	FILE* f = fopen(nome_arquivo, "r");
	if (f == NULL) {
		perror("Nao pude abrir o arquivo");
		return -1;
	}

	int matriz[LINHAS][COLUNAS];
	int i, j;

	for (i=0; i<LINHAS; ++i) {
		for (j=0; j<COLUNAS; ++j) {
			int num;
			fscanf(f, "%d", &num);
			matriz[i][j] = num;
		}
	}

	for (i=0; i<LINHAS; ++i) {
		for (j=0; j<COLUNAS; ++j) {
			printf("%2d ", matriz[i][j]);
		}
		putchar('\n');
	}

	fclose(f);
	return 0;
}
