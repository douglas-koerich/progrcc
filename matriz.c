#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LINHAS	2
#define COLUNAS	3

// Prototipo da funcao: multiplica o num (1o. parametro) pela matriz guardando
// o resultado na propria matriz passada como parametro
void produtoEscalar(int, size_t, size_t, int[*][*]);

int main() {
	srand((unsigned) time(0));

	// O primeiro par de [] eh das linhas, o segundo das colunas
	int matriz[LINHAS][COLUNAS] = { {1, 2, 3}, {4, 5, 6} }, // exemplo de inicializacao
		segunda[LINHAS][COLUNAS], soma[][COLUNAS] = { {0}, {0} };
		// errada[][] = { {1, 10, 5} , {2, 4, 6} }	// nao se pode deixar ambos os colchetes vazios
		// 											// soh pode deixar o PRIMEIRO (das linhas) vazio

	// Vamos preencher a matriz
	int lin, col;
	for (lin=0; lin<LINHAS; ++lin) {
		for (col=0; col<COLUNAS; ++col) {
			matriz[lin][col] = rand() % 100;	// aleatorio de 0 a 99
		}
	}

	// Vamos preencher a segunda matriz de forma diferente...
	for (col=0; col<COLUNAS; ++col) {
		for (lin=0; lin<LINHAS; ++lin) {
			printf("Digite o elemento na posicao [%d][%d]: ", lin, col);
			scanf("%d", &segunda[lin][col]);	// aqui NAO inverte os indices!!!
		}
	}

	// Somando as matrizes
	for (lin=0; lin<LINHAS; ++lin) {
		for (col=0; col<COLUNAS; ++col) {
			soma[lin][col] = matriz[lin][col] + segunda[lin][col];
		}
	}
	
	// Imprimindo a matriz aleatoria
	for (lin=0; lin<LINHAS; ++lin) {
		for (col=0; col<COLUNAS; ++col) {
			printf("%5d", matriz[lin][col]);
		}
		putchar('\n');	// comeca nova linha da margem esquerda
	}
	
	// Imprimindo a matriz soma
	putchar('\n');
	for (lin=0; lin<LINHAS; ++lin) {
		for (col=0; col<COLUNAS; ++col) {
			printf("%5d", soma[lin][col]);
		}
		putchar('\n');
	}

	// Lendo o fator do usuario
	int fator;
	printf("Digite o fator a multiplicar pela segunda matriz: ");
	scanf("%d", &fator);
	produtoEscalar(fator, COLUNAS, LINHAS, segunda);

	// Imprimindo a matriz multiplicada
	for (lin=0; lin<LINHAS; ++lin) {
		for (col=0; col<COLUNAS; ++col) {
			printf("%5d", segunda[lin][col]);
		}
		putchar('\n');
	}
	
	return 0;
}

void produtoEscalar(int num, size_t col, size_t lin, int mat[lin][col]) {
	size_t l, c;
	for (l=0; l<lin; ++l) {
		for (c=0; c<col; ++c) {
			mat[l][c] *= num;
		}
	}
}

