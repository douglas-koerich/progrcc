#include <stdio.h>

// #define TAM	3

float calculaDeterminante(size_t, float[*][*]);

int main(void) {
	// float matriz[TAM][TAM];
	size_t dim;
	int lin, col;

	printf("Digite a dimensao da matriz quadrada: ");
	scanf("%u", &dim);

	// Matriz de tamanho "variavel" (em funcao de uma variavel)
	float matriz[dim][dim];

	for (lin = 0; lin < dim; ++lin) {
		for (col = 0; col < dim; ++col) {
			printf("Digite o valor do elemento [%d][%d]: ", lin, col);
			scanf("%f", &matriz[lin][col]);
		}
	}

	for (lin = 0; lin < dim; ++lin) {
		for (col = 0; col < dim; ++col) {
			printf("%6.3f ", matriz[lin][col]);
		}
		putchar('\n');
	}

	float determinante = calculaDeterminante(dim, matriz);

	printf("O determinante da matriz eh %.3f\n", determinante);

	return 0;
}

float calculaDeterminante(size_t dim, float matriz[dim][dim]) {
	float principal = 1.0;
	int i;
	for (i = 0; i < dim; ++i) {
		principal *= matriz[i][i];
	}

	float secundaria = 1.0;
	for (i = 0; i < dim; ++i) {
		secundaria *= matriz[i][dim-1-i];
	}
	return principal - secundaria;
}

