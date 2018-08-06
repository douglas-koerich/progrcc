#include <stdio.h>

void limpaTela(void) {
	system("clear");
}

// y = f(x) = x!
double f(double x) {
	double y, i;
	for (y=1.0, i=1.0; i<=x; ++i) {
		y = y * i;
	}
	return y;
}

int main() {
	double n, r;
	printf("Digite o numero total de elementos (n): ");
	scanf("%lf", &n);
	printf("Digite o numero de elementos numa combinacao (r): ");
	scanf("%lf", &r);

	double fat_n = f(n);
	double fat_r = f(r);
	double fat_n_menos_r = f(n-r);
	double C = fat_n / (fat_r * fat_n_menos_r);

	limpaTela();
	printf("O numero de combinacoes eh %.0lf.\n", C);

	return 0;
}

