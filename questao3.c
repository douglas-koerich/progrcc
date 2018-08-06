#include <stdio.h>
#include <math.h>

int main() {
	int a = 0, b = 1;	// integral de 0 a 1
	float pi, S = 0, A;		// inicia soma com 0
	float x_i, x_i_1, y_i, y_i_1;
	int n, i;
	float delta_x;

	printf("Digite o numero de divisoes: ");
	scanf("%d", &n);
	delta_x = b - a;
	delta_x /= n;

	x_i_1 = a;
	x_i = x_i_1 + delta_x;

	// Temos que somar n areas
	for (i=1; i<=n; ++i) {
		y_i_1 = 1.0/(1 + pow(x_i_1, 2));
		y_i = 1.0/(1 + pow(x_i, 2));

		A = (y_i + y_i_1)/2 * delta_x;

		S += A;

		x_i_1 = x_i;
		x_i = x_i + delta_x;
	}

	pi = 4 * S;

	printf("pi = %f\n", pi);
	return 0;
}

