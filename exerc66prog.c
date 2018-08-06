#include <stdio.h>

int main() {
	unsigned N, n = 1;
	float S = 0.0;	// inicializa

	printf("Digite o valor de N: ");
	scanf("%u", &N);

	while (n <= N) {
		S += (n*n + 1.0)/(n + 3);
		++n;
	}
	printf("O valor da soma eh %.3f.\n", S);

	return 0;
}

