#include <stdlib.h>
#include <stdio.h>

#define N	3	// linhas
#define M	4	// colunas

// 1o. parametro: numero de linhas (tipo size_t)
// 2o. parametro: numero de colunas (tambem do tipo size_t)
// 3o. parametro: a matriz que vai ser invertida/impressa

void inverteLinhas(size_t, size_t, int [*][*]);
void imprimeMatriz(size_t, size_t, int [*][*]);

int main() {
	int matriz[N][M];	// conforme enunciado
	int linha, coluna;

	for (linha=0; linha<N; ++linha) {
		for (coluna=0; coluna<M; ++coluna) {
			printf("Digite o valor do elemento [%d][%d]: ", linha, coluna);
			scanf("%d", &matriz[linha][coluna]);
		}
	}
	imprimeMatriz(N, M, matriz);

	// Chama a funcao para preencher o vetor com a soma de cada coluna
	inverteLinhas(N, M, matriz);	// nao use [] na chamada

	putchar('\n');
	imprimeMatriz(N, M, matriz);
	
	return 0;
}

void imprimeMatriz(size_t lin, size_t col, int m[lin][col]) {
	int l, c;
	for (l=0; l<lin; ++l) {
		for (c=0; c<col; ++c) {
			printf("%4d ", m[l][c]);
		}
		putchar('\n');
	}
}

void inverteLinhas(size_t lin, size_t col, int m[lin][col]) {
	int l1 = 0, l2 = lin-1, c;
	while (l1 < l2) {
		for (c=0; c<col; ++c) {
			// Desculpa, Profa. Patricia, foi mal... :-(
			/*
			int baldinho = m[l2][c];
			m[l2][c] = m[l1][c];
			m[l1][c] = baldinho;
			*/
			// A magica (e beleza) dos operadores binarios!...
			m[l1][c] = m[l1][c] ^ m[l2][c];
			m[l2][c] = m[l1][c] ^ m[l2][c];
			m[l1][c] = m[l1][c] ^ m[l2][c];
		}
		++l1, --l2;	
	}
}
