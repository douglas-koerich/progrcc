#include <stdio.h>

#define LINHAS	3	// ao inves do 5 do enunciado
#define COLUNAS	4	// ao inves do 7

main() {
	int A[LINHAS][COLUNAS];
	int i, j, coluna_do_menor, linha_do_maior, i2;

	for (i=0; i<LINHAS; ++i) {
		for (j=0; j<COLUNAS; ++j) {
			printf("Digite A[%d][%d]: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
	for (i=0; i<LINHAS; ++i) {
		for (j=0; j<COLUNAS; ++j) {
			printf("%3d ", A[i][j]);
		}
		putchar('\n');
	}
	for (i=0; i<LINHAS; ++i) {
		for (coluna_do_menor=j=0; j<COLUNAS; ++j) {
			if (A[i][j] < A[i][coluna_do_menor]) {
				coluna_do_menor = j;
			}
		}
		for (linha_do_maior=i2=0; i2<LINHAS; ++i2) {
			if (A[i2][coluna_do_menor] > A[linha_do_maior][coluna_do_menor]) {
				linha_do_maior = i2;
			}
		}
		if (linha_do_maior == i) {
			printf("Ponto de sela em A[%d][%d] = %d.\n", linha_do_maior, coluna_do_menor, A[linha_do_maior][coluna_do_menor]);
		}
	}	
}

