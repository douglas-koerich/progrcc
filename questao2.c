/* e^x = 1 + x^1/1! + x^2/2! + x^3/3! + ... */

#include <stdio.h>
#include <math.h>

int main() {
	int x, num = 1, fat, i;
	float e_x_original, e_x_serie = 1, dif;

	printf("Digite o expoente x: ");
	scanf("%d", &x);

	e_x_original = exp(x);
	dif = e_x_original - e_x_serie;

	/*
	if (dif < 0) {
		dif = -dif;
	}
	*/

	while (dif < -0.0001 || dif > 0.0001) {
		// Tem que somar mais um termo...
		for (i=fat=1; i<=num; ++i) {	// calculo de num!
			fat *= i;
		}
		e_x_serie += pow(x, num) / fat;
		dif = e_x_original - e_x_serie;
		++num;
	}

	printf("x = %d\n", x);
	printf("e_x_serie = %f\n", e_x_serie);
	printf("e_x_original = %f\n", e_x_original);
	printf("termos = %d\n", num);

	return 0;
}

