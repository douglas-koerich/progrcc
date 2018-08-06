#include <stdio.h>
#include <math.h>

int main() {
	float x1, y1, x2, y2;

	printf("Digite as coordenadas do ponto P:\n");
	printf("X1? "); scanf("%f", &x1);
	printf("Y1? "); scanf("%f", &y1);

	printf("Agora digite as coordenadas do ponto Q:\n");
	printf("X2? "); scanf("%f", &x2);
	printf("Y2? "); scanf("%f", &y2);

	float delta_x = pow(x2-x1, 2);	// x2-x1 eh base, 2 eh expoente
	float delta_y = pow(y2-y1, 2);

	float d = sqrt(delta_x + delta_y);

	printf("A distancia entre P e Q eh %.3f.\n", d);

	return 0;
}

