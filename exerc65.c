#include <stdio.h>

double combinacao(unsigned, unsigned);

int main(void) {
	unsigned n, p;
	double C;	// para calcular a mega-sena ;-P

	printf("Digite o numero total de elementos (n): ");
	scanf("%u", &n);
	printf("Digite o numero de elementos da combinacao (p): ");
	scanf("%u", &p);

	C = combinacao(n, p);

	printf("O numero de combinacoes eh %e.\n", C);

	return 0;
}

double fatorial(unsigned x) {
	double fat = 1.0;
	if (x > 0) {
		int i;
		for (i = 1; i <= x; ++i) {
			fat *= i;
		}
	}
	return fat;
}

double combinacao(unsigned n, unsigned r) {
	double C;
	C = fatorial(n) / (fatorial(r) * fatorial(n-r));
	return C;
}

