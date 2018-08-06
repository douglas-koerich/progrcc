#include <stdio.h>

#define TAMANHO		10	// nao tem ponto-e-virgula no fim desta linha

int main(void) {
	int i, A[TAMANHO], vetor[TAMANHO];

	/*
	printf("Digite o primeiro elemento: ");
	scanf("%d", &A[0]);
	printf("Digite o segundo elemento: ");
	scanf("%d", &A[1]);
	...
	*/
	for (i=0; i<TAMANHO; ++i) {	// laco para percorrer o vetor A...
		printf("Digite o elemento %d: ", i);
		scanf("%d", &A[i]);

		vetor[i] = 1;
		int j;
		for (j=1; j<=A[i]; ++j) {
			vetor[i] *= j;
		}
	}
	for (i=0; i<TAMANHO; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
	for (i=0; i<TAMANHO; ++i) {
		printf("%d ", vetor[i]);
	}
	printf("\n");
	return 0;
}

