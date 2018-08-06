#include <stdio.h>

// Prototipos de funcoes que recebem vetores
void impvetor(int [*], int);
void fatvetor(int [*], int [*] , int);
int fatorial(int);

#define NUM	10

int main() {
	int vetor_A[NUM], vetor_F[NUM], i;

	for (i=0; i<NUM; ++i) {
		printf("Digite o elemento %i do vetor A: ", i);
		scanf("%d", &vetor_A[i]);
	}

	printf("Vetor de inteiros: ");
	impvetor(vetor_A, NUM);

	fatvetor(vetor_A, vetor_F, NUM);

	printf("Vetor de fatoriais: ");
	impvetor(vetor_F, NUM);

	return 0;
}

void impvetor(int vetor_X[], int tamanho) {
	int i;
	for (i=0; i<tamanho; ++i) {
		printf("%d ", vetor_X[i]);
	}
	printf("\n");
}

void fatvetor(int vetor_X[], int vetor_Y[], int tamanho) {
	int i;
	for (i=0; i<tamanho; ++i) {
		vetor_Y[i] = fatorial(vetor_X[i]);
	}
}

int fatorial(int n) {
	int f, i;
	for (i=f=1; i<=n; ++i) {
		f *= i;
	}
	return f;
}

