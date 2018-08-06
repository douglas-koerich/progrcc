#include <stdio.h>

#define ORDEM_MATRIZ	3

float calculaDeterminante(int, float [*][*]);	// primeiro o(s) tamanho(s)

int main() {
	float matriz[ORDEM_MATRIZ][ORDEM_MATRIZ];	// matriz 3x3

	// Percorrer a matriz preenchendo-a
	int linha, coluna;
	for (linha = 0; linha < ORDEM_MATRIZ; ++linha) {
		// Percurso dentro do "vetor"-linha (coluna por coluna)
		for (coluna = 0; coluna < ORDEM_MATRIZ; ++coluna) {
			printf("Digite o elemento [%d][%d]: ", linha, coluna);
			scanf("%f", &matriz[linha][coluna]);
		}
	}
	// Imprime a matriz
	for (linha = 0; linha < ORDEM_MATRIZ; ++linha) {
		for (coluna = 0; coluna < ORDEM_MATRIZ; ++coluna) {
			printf("%6.2f\t", matriz[linha][coluna]);
		}
		putchar('\n');	// Salta linha na tela antes da proxima (linha)
	}
	// Calculo do determinante
	float determinante = calculaDeterminante(ORDEM_MATRIZ, matriz);
	printf("O determinante vale %.2f.\n", determinante);
	return 0;
}

float calculaDeterminante(int ordem, float m[ordem][ordem]) {
	float det = 1.0;	// inicia produto com elemento neutro da multiplic.
	int posicao;
	for (posicao = 0; posicao < ordem; ++posicao) {
		det *= m[posicao][posicao];	// diag princ linha = coluna
	}
	return det;
}

