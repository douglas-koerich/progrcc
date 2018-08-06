#include <stdlib.h>	// rand(), srand(), malloc() e free()
#include <time.h>	// time()
#include <stdio.h>

void imprimeVetor(int*, size_t);

int main() {
	// Inicializa o gerador ("semente") de numeros pseudo-aleatorios
	srand(time(0));

	int n;
	do {
		printf("Digite o tamanho do vetor (quantos numeros): ");
		scanf("%d", &n);
	} while (n < 1 || n > 20);

	int* v = (int*) malloc(n * sizeof(int));

	int m;
	printf("Quantas posicoes sera deslocado (a esquerda)? ");
	scanf("%d", &m);

	int i;
	for (i=0; i<n; ++i) {
		*(v+i) = rand() % 50;
	}
	printf("Vetor original: ");
	imprimeVetor(v, n);

	// Realiza os deslocamentos do vetor a esquerda
	int j;
	for (j=1; j<=m; ++j) {
		int backup = *v;		// salva o primeiro elemento (v[0] <=> *v)
		for (i=0; i<n-1; ++i) {	// note que NAO eh i<n...
			*(v+i) = *(v+i+1);	// ... por causa do i+1 nesta linha
		}
		*(v+n-1) = backup;	// recupera o antigo primeiro para por no ultimo
		printf("Apos %do. passo: ", j);
		imprimeVetor(v, n);
	}
	
	free(v);
	
	return 0;
}

void imprimeVetor(int* x, size_t t) {
	int i;
	for (i=0; i<t; ++i) {
		printf("%d ", x[i]);	// indexacao de um ponteiro
	}
	printf("\n");
}
