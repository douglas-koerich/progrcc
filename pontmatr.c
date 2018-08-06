#include <stdio.h>

#define LIN 3
#define COL 4

int main() {
	float m[LIN][COL];

	int l, c, x = 1;
	for (l=0; l<LIN; ++l) {
		for (c=0; c<COL; ++c) {
			// Preenche a matriz com numeros em sequencia
			m[l][c] = x++;
		}
	}
	// Imprimindo a matriz deslocando o ponteiro dentro dela
	float* p = &m[0][0];
	for (l=0; l<LIN; ++l) {
		for (c=0; c<COL; ++c) {
			printf("%4.1f ", *p);
			++p;
		}
		putchar('\n');
	}

	// Imprimindo a matriz com um ponteiro SEM desloca-lo dentro dela
	float* q = &m[0][0];
	for (l=0; l<LIN; ++l) {
		for (c=0; c<COL; ++c) {
			printf("%4.1f ", *(q+l*COL+c));	// +l*COL pra saltar p/ a linha
											// +c pra saltar p/ a coluna
		}
		putchar('\n');
	}
	
	return 0;
}
