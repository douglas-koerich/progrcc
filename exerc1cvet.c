#include <stdio.h>
#include <stdbool.h>

#define TAM 10

int main() {
	int X[TAM], Y[TAM], S[TAM];
	int i;

	for (i=0; i<TAM; ++i) {
		bool repetiu;
		do {
			printf("Digite o valor de X[%d]: ", i);
			scanf("%d", &X[i]);
			int j;
			repetiu = false;
			for (j=i-1; j>=0; --j) {
				if (X[j] == X[i]) {
					repetiu = true;
				}
			}
		} while (repetiu == true);
	}
	for (i=0; i<TAM; ++i) {
		bool repetiu;
		do {
			printf("Digite o valor de Y[%d]: ", i);
			scanf("%d", &Y[i]);
			int j;
			repetiu = false;
			for (j=i-1; j>=0; --j) {
				if (Y[j] == Y[i]) {
					repetiu = true;
				}
			}
		} while (repetiu == true);
	}

	// Letra (c)
	for (i=0; i<TAM; ++i) {
		S[i] = X[i] + Y[i];
		printf("S[%d] = %d\n", i, S[i]);
	}
	return 0;
}

