#include <stdio.h>

// void rotaciona(int v[], int n, int m);
void rotaciona(int* v, int n, int m);

int main() {
	int n, m;

	printf("Digite o tamanho do vetor (n): ");
	scanf("%d", &n);

	int vetor[n];

	puts("Agora preencha o vetor:");
	int i;
	int* pi = vetor;	// int* pi = &vetor[0];
	for (i=0; i<n; ++i) {
		printf("Elemento %d: ", i);
		// scanf("%d", &vetor[i]);
		scanf("%d", pi+i);
	}

	puts("Vetor antes do deslocamento:");
	int* pj = vetor;
	for (i=0; i<n; ++i, ++pj) {
		// printf("%d ", vetor[i]);
		printf("%d ", *pj);
	}
	putchar('\n');

	printf("Quantas posicoes vai deslocar (m)? ");
	scanf("%d", &m);

	/*
	int j;
	for (j=1; j<=m; ++j) {	// vai fazer m vezes o deslocamento de 1 p/ esq
		// int aux = vetor[0];
		int aux = *vetor;	// int aux = *(vetor+0);
		for (i=1; i<n; ++i) {
			// vetor[i-1] = vetor[i];
			*(vetor+i-1) = *(vetor+i);
		}
		// vetor[n-1] = aux;
		*(vetor+n-1) = aux;
	}
	*/
	rotaciona(vetor, n, m);

	puts("Vetor depois do deslocamento:");
	for (i=0; i<n; ++i) {
		printf("%d ", vetor[i]);
	}
	putchar('\n');

	return 0;
}

void rotaciona(int* v, int n, int m) {
	int i, j;
	for (j=1; j<=m; ++j) {	// vai fazer m vezes o deslocamento de 1 p/ esq
		// int aux = vetor[0];
		int aux = *v;	// int aux = *(vetor+0);
		for (i=1; i<n; ++i) {
			// vetor[i-1] = vetor[i];
			*(v+i-1) = *(v+i);
		}
		// vetor[n-1] = aux;
		*(v+n-1) = aux;
	}
}

