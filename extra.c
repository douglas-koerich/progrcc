#include <stdio.h>

int main(void) {
	int n, a = 0, b = 1, passo;
	float S, delta_x, x, y, y_ant, A, pi;

	printf("Digite o numero de divisoes sob a curva: ");
	scanf("%d", &n);

	delta_x = (float)(b - a) / n;

	y_ant = 1.0 / (1 + a*a); // y_0
	for (passo = 1, x = a, S = 0.0; passo <= n; ++passo, x += delta_x) {
		y = 1.0 / (1 + x*x);
		A = (y + y_ant) * delta_x / 2;
		S += A;
		y_ant = y;
	}
	pi = 4 * S;
	printf("Pi aproximado pela integral = %f.\n", pi);
	return 0;
}

