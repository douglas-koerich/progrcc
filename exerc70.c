#include <stdio.h>
#include <math.h>

int main(void) {
	int n;

	printf("Quantos elementos tera o vetor? ");
	scanf("%d", &n);

	// Declara o vetor com o tamanho escolhido pelo usuario
	float x[n];

	// Preenche o vetor com valores
	int i;
	for (i=0; i<n; ++i) {
		printf("Digite o x%d: ", i+1);
		scanf("%f", &x[i]);
	}
	// Calcula a media ("x barra")
	float x_barra, soma = 0.0;
	for (i=0; i<n; ++i) {
		soma += x[i];
	}
	x_barra = soma / n;

	// Calculo do desvio medio
	float DM;
	for (i=0, soma = 0.0; i<n; ++i) {
		// Algoritmo para somar o MODULO da diferenca
		if (x[i] < x_barra) {
			soma += x_barra - x[i];
		}
		else {
			soma += x[i] - x_barra;
		}
	}
	DM = soma / n;

	// Calculo do desvio padrao
	// ATENCAO! A formula do enunciado esta ERRADA, o quadrado eh da
	// diferenca, e nao soh da media
	float sigma;
	for (i=0, soma = 0.0; i<n; ++i) {
		soma += pow(fabsf(x[i] - x_barra), 2);
	}
	sigma = sqrt(soma / (n-1));

	printf("Media = %.3f\n", x_barra);
	printf("Desvio medio = %.3f\n", DM);
	printf("Desvio padrao = %.3f\n", sigma);

	return 0;
}

