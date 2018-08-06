#include <stdio.h>

#define	TAMANHO	10	// Numero de elementos, NAO o tamanho em memoria (bytes)

int main() {
	int X[TAMANHO] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 },	// todos inicializados
		Y[TAMANHO] = { 1, 2, 3, 4, 5 };		// inicializou primeiros, 0 nos demais
	int i;
	for (i=0; i<TAMANHO; ++i) {
		int ehRepetido;
		do {
			ehRepetido = 0;	// comeca o laco assumindo que nao vai repetir
			printf("Digite o %do. numero do vetor X: ", i+1);
			scanf("%d", &X[i]);
			int j;
			for (j=0; j<i; ++j) {
				if (X[i] == X[j]) {	// repetindo o numero?
					ehRepetido = 1;	// muda para 'repetido' = verdadeiro
				}
			}
		} while (ehRepetido == 1);
	}
	for (i=0; i<TAMANHO; ++i) {
		int ehRepetido;
		do {
			ehRepetido = 0;	// comeca o laco assumindo que nao vai repetir
			printf("Digite o %do. numero do vetor Y: ", i+1);
			scanf("%d", &Y[i]);
			int j;
			for (j=0; j<i; ++j) {
				if (Y[i] == Y[j]) {	// repetindo o numero?
					ehRepetido = 1;	// muda para 'repetido' = verdadeiro
				}
			}
		} while (ehRepetido == 1);
	}
	// Impressao dos vetores na ordem direta (do primeiro para o ultimo)
	for (i=0; i<TAMANHO; ++i) {
		printf("%d ", X[i]);
	}
	printf("\n");
	for (i=0; i<TAMANHO; ++i) {
		printf("%d ", Y[i]);
	}
	printf("\n");

	// Impressao na ordem inversa
	for (i=TAMANHO-1; i>=0; --i) {
		printf("%d ", X[i]);
	}
	printf("\n");
	for (i=TAMANHO-1; i>=0; --i) {
		printf("%d ", Y[i]);
	}
	printf("\n");

	// Item a: U = X U Y
	int U[2*TAMANHO] = { 0 };	// vetor zerado
	for (i=0; i<TAMANHO; ++i) {
		U[i] = X[i];
	}
	int u = TAMANHO;	// proxima posicao livre em U para copiar de Y
	for (i=0; i<TAMANHO; ++i) {
		int j, ehRepetido = 0;
		for (j=0; j<TAMANHO; ++j) {
			if (Y[i] == X[j]) {	// o i-esimo de Y existe em X
				ehRepetido = 1;
			}
		}
		// Ao terminar de percorrer X, testa variavel-flag 'ehRepetido'
		if (!ehRepetido) { // (ehRepetido == 0)
			U[u] = Y[i];
			++u;
		}
	}
	for (i=0; i<2*TAMANHO; ++i) {
		printf("%d ", U[i]);
	}
	printf("\n");

	// Item c: S = X + Y
	int S[TAMANHO] = { 0 }; // todas as posicoes-somas zeradas
	for (i=0; i<TAMANHO; ++i) {
		S[i] = X[i] + Y[i];
		printf("%d ", S[i]);
	}
	printf("\n");
	return 0;
}

