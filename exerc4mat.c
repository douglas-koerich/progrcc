#include <stdlib.h>
#include <stdio.h>

#define N	3	// linhas
#define M	4	// colunas

// 1o. parametro: numero de linhas (tipo size_t)
// 2o. parametro: numero de colunas (tambem do tipo size_t)
// 3o. parametro: a matriz que vai ser vasculhada
// 4o. parametro: o vetor que vai ser preenchido
void somaColunas(size_t, size_t, int [*][*], int[*]);

int main() {
	int matriz[N][M];	// conforme enunciado
	int vetor[M];		// mesma dimensao do numero de colunas da matriz

	int linha, coluna;

	for (linha=0; linha<N; ++linha) {
		for (coluna=0; coluna<M; ++coluna) {
			printf("Digite o valor do elemento [%d][%d]: ", linha, coluna);
			scanf("%d", &matriz[linha][coluna]);
		}
	}

	// Imprime a matriz como foi digitada
	for (linha=0; linha<N; ++linha) {
		for (coluna=0; coluna<M; ++coluna) {
			printf("%4d ", matriz[linha][coluna]);
		}
		putchar('\n');
	}

	// Chama a funcao para preencher o vetor com a soma de cada coluna
	somaColunas(N, M, matriz, vetor);	// nao use [] na chamada
	
	// Imprime o vetor logo abaixo da matriz
	putchar('\n');
	for (coluna=0; coluna<M; ++coluna) {
		printf("%4d ", vetor[coluna]);
	}
	putchar('\n');
	return 0;
}

// A ordem dos parametros eh importante: definem-se os tamanhos antes da
// matriz e do vetor que usam os tamanhos em suas definicoes
void somaColunas(size_t lin, size_t col, int m[lin][col], int v[col]) {
	int l, c;
	for (c=0; c<col; ++c) {
		v[c] = 0;
		for (l=0; l<lin; ++l) {
			v[c] += m[l][c];	// nao troca a ordem nos []s!!
		}
	}
}
