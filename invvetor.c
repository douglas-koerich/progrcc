#include <stdlib.h>
#include <stdio.h>

void inverte(int [*], size_t);

int main() {
	printf("Digite o tamanho: ");
	size_t tamanho;
	scanf("%u", &tamanho);

	int vetor[tamanho];

	int i;
	for (i=0; i<tamanho; ++i) {
		vetor[i] = i;
	}

	printf("Antes: ");
	for (i=0; i<tamanho; ++i) {
		printf("%d ", vetor[i]);
	}
	printf("\n");

	inverte(vetor, tamanho);

	printf("Depois: ");
	for (i=0; i<tamanho; ++i) {
		printf("%d ", vetor[i]);
	}
	printf("\n");

	return 0;
}

void inverte(int v[], size_t t) {
	int aux, i, j;
	for (i=0, j=t-1; i<j; ++i, --j) {
		aux = v[j];
		v[j] = v[i];
		v[i] = aux;
	}
}

