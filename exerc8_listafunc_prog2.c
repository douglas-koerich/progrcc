#include <stdio.h>

double calculaSoma(unsigned);

int main() {
	unsigned N;
	double S;

	do {
		printf("Digite o valor de N: ");
		scanf("%d", &N);
	} while (N == 0);
	S = calculaSoma(N);
	printf("S = %.3lf\n", S);
	return 0;
}

double calculaSoma(unsigned X) {
	double Y = 0.0;
	unsigned n = 1;

	while (n <= X) {
		Y += (double)(n*n+1)/(n+3);	// senao vai ser div. inteira
		++n;
	}
	return Y;
}

