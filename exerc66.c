#include <stdio.h>

float calculaSoma(unsigned);

int main(void) {
	unsigned termos;

	printf("Digite o numero de parcelas (N): ");
	scanf("%u", &termos);

	printf("A soma das parcelas eh %.2f\n", calculaSoma(termos));

	return 0;
}

float calculaSoma(unsigned N) {
	float S = 0.0;
	unsigned n;
	for (n = 1; n <= N; ++n) {
		S += (n*n + 1.0)/(n + 3.0);
	}
	return S;
}

