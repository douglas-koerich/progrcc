#include <stdio.h>

int main() {
	double n, r;
	printf("Digite o numero total de elementos (n): ");
	scanf("%lf", &n);
	printf("Digite o numero de elementos numa combinacao (r): ");
	scanf("%lf", &r);

	double fat_n, x;
	for (fat_n=1.0, x=1.0; x<=n; ++x) {
		fat_n = fat_n * x;
	}
	double fat_r;
	for (fat_r=x=1.0; x<=r; ++x) {
		fat_r *= x;
	}
	double fat_n_menos_r;
	for (fat_n_menos_r=x=1.0; x<=(n-r); ++x) {
		fat_n_menos_r *= x;
	}
	double C = fat_n / (fat_r * fat_n_menos_r);

	printf("O numero de combinacoes eh %.0lf.\n", C);

	return 0;
}

