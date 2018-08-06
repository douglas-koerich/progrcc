#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LINHAS 5
#define COLUNAS 3

int main() {
	FILE* f = fopen("/tmp/tabela.txt", "w");
	if (f == NULL) {
		perror("Nao pude criar o arquivo para a tabela");
		return -1;
	}
	srand((unsigned) time(0));

	int matriz[LINHAS][COLUNAS];

	// Preenche a matriz com numeros randomicos ate 100 (exclusive)
	int i, j;
	for (i=0; i<LINHAS; ++i) {
		for (j=0; j<COLUNAS; ++j) {
			matriz[i][j] = rand() % 100;
			printf("%2d ", matriz[i][j]);
			if (fprintf(f, "%2d ", matriz[i][j]) < 0) {
				perror("Nao pude escrever o numero no arquivo");
				fclose(f);
				return -1;
			}
		}
		putchar('\n'); // separa linhas da matriz na tela
		/* Se eu fizer questao de separar as linhas tambem no arquivo-texto
		if (fputc('\n', f) == EOF) {
			perror("Nao pude separar as linhas no arquivo");
			fclose(f);
			return -1;
		}
		*/
	}

	fclose(f);
	return 0;
}
