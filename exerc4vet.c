#include <stdlib.h>	// size_t
#include <stdio.h>
#include <math.h>	// fabsf, pow e sqrt

float calculaMedia(int [*], size_t);	// extra (auxiliar para as outras)
float calculaDM(int [*], size_t, float);
float calculaSigma(int [*], size_t, float);

#define TAM_VETOR	10

int main() {
	int vetor[TAM_VETOR] = { 0 };	// inicializa TODO o vetor com zeros

	// Preenche o vetor
	int i;
	for (i=0; i<TAM_VETOR; ++i) {
		printf("Digite vetor[%d]: ", i);
		scanf("%d", &vetor[i]);
	}
	float media = calculaMedia(vetor, TAM_VETOR);
	float DM = calculaDM(vetor, TAM_VETOR, media);
	float sigma = calculaSigma(vetor, TAM_VETOR, media);

	printf("O desvio medio (DM) eh igual a %.3f\n", DM);
	printf("O desvio padrao (sigma) eh igual a %.3f\n", sigma);

	return 0;
}

float calculaMedia(int x[], size_t n) {
	float soma = 0.0;
	int i;
	for (i=1; i<=n; ++i) {	// seguindo a formula do numerador
		soma += x[i-1];
	}
	float x_barra = soma / n;
	return x_barra;
}

float calculaDM(int x[], size_t n, float x_barra) {
	float soma = 0.0;
	int i;
	for (i=1; i<=n; ++i) {
		soma += fabsf(x[i-1] - x_barra);
	}
	float DM = soma / n;
	return DM;
}

float calculaSigma(int x[], size_t n, float x_barra) {
	float soma = 0.0;
	int i;
	for (i=1; i<=n; ++i) {
		soma += pow((x[i-1] - x_barra), 2);
	}
	float sigma = sqrt(soma / (n-1));
	return sigma;
}

