#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ORDEM_MATRIZ	6

void multiplica(int, int [*][*]);
void imprime(int, int [*][*]);

int main() {
	srand((unsigned) time(0));

	int matriz[ORDEM_MATRIZ][ORDEM_MATRIZ];	// matriz 6x6

	// Percorrer a matriz preenchendo-a
	int linha, coluna;
	for (linha = 0; linha < ORDEM_MATRIZ; ++linha) {
		// Percurso dentro do "vetor"-linha (coluna por coluna)
		for (coluna = 0; coluna < ORDEM_MATRIZ; ++coluna) {
			matriz[linha][coluna] = rand() % 50 + 1;
		}
	}
	// Imprime a matriz antes...
	puts("MATRIZ ANTES DA MULTIPLICACAO:");
	imprime(ORDEM_MATRIZ, matriz);

	// Multiplica cada elemento da linha pelo valor do elemento na diagonal
	// secundaria daquela linha
	multiplica(ORDEM_MATRIZ, matriz);

	// Imprime a matriz depois...
	puts("\nMATRIZ DEPOIS DA MULTIPLICACAO:");
	imprime(ORDEM_MATRIZ, matriz);
	return 0;
}

void imprime(int ordem, int m[ordem][ordem]) {
	int linha, coluna;
	for (linha = 0; linha < ordem; ++linha) {
		for (coluna = 0; coluna < ordem; ++coluna) {
			printf("%2d\t", m[linha][coluna]);
		}
		putchar('\n');	// Salta linha na tela antes da proxima (linha)
	}
}

void multiplica(int ordem, int m[ordem][ordem]) {
	int linha, coluna;
	for (linha = 0; linha < ordem; ++linha) {
		// diag secundaria: (linha + coluna) dah sempre (ordem - 1)
		// entao, isolando coluna fica: coluna = ordem - 1 - linha
		int aux = m[linha][ordem-1-linha];
		for (coluna = 0; coluna < ordem; ++coluna) {
			m[linha][coluna] *= aux;
		}
	}
}

