#include <stdio.h>
#include <math.h>

float somatorio(unsigned);

int main(void) {
	unsigned N;

	printf("Digite o valor de N: ");
	scanf("%u", &N);

	float S;
	S = somatorio(N);

	printf("A soma da expressao resultou %.4f\n", S);

	return 0;
}

float somatorio(unsigned N) {
	unsigned n;
	float S;
	for (n=1, S=0.0; n<=N; ++n) {
		S += (pow(n, 2) + 1) / (n + 3);
	}
	return S;
}


