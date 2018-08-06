#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LINHAS 3
#define COLUNAS 4

void imprime(int*, size_t, size_t);

int main() {
	int matriz[LINHAS][COLUNAS];

	srand((unsigned) time(0));

	int l, c;
	for (l=0; l<LINHAS; ++l) {
		for (c=0; c<COLUNAS; ++c) {
			matriz[l][c] = rand() % 100;
		}
	}
	// Faz um cast para (int*) de modo a interpretar 'matriz' como
	// o endereco do elemento 0,0 (que ele eh de fato!), e nao um
	// endereco de vetores (*[])
	imprime((int*) matriz, LINHAS, COLUNAS);

	return 0;
}

void imprime(int* m, size_t l, size_t c) {
	size_t ll, cc;
	for (ll=0; ll<l; ++ll) {
		for (cc=0; cc<c; ++cc) {
			// printf("%4d", m[ll][cc]);
			printf("%4d", *(m + ll*c + cc));	// endereco + ind_linha*NUM_COLS + ind_coluna
		}
		putchar('\n');
	}
}

