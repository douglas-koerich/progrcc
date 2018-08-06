#include <stdio.h>
#include <math.h>

#define	MAX	50

main() {
	unsigned N, i;
	float vetor_x[MAX], m, sigma = 0.0, soma;

	do {
		printf("Digite o numero de termos: ");
		scanf("%u", &N);
	}
	while (N <= 1 || N > MAX);

	for (i=0, soma=0.0; i<N; ++i) {
		printf("Digite o valor de x(%u): ", i+1);
		scanf("%f", &vetor_x[i]);

		soma += vetor_x[i];
	}
	m = soma / N;
/*
	for (i=0, soma=0.0; i<N; ++i) {
		soma += pow(vetor_x[i], 2) - N*pow(m, 2);
	}
	sigma = sqrt(soma/(N-1));
*/
	printf("m = %.2f, sigma = %.2f\n", m, sigma);
}
	
