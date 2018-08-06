#include <stdio.h>
#include <math.h>

int calculaRaizes2o_Grau(float, float, float, float*, float*);

int main() {
	float a, b, c, x1, x2;

	printf("Digite o coeficiente de x^2: "); scanf("%f", &a);
	printf("Digite o coeficiente de x: "); scanf("%f", &b);
	printf("Digite o termo independente: "); scanf("%f", &c);

	if (!calculaRaizes2o_Grau(a, b, c, &x1, &x2)) {
		puts("Nao existem raizes reais!");
	}
	else {
		printf("As raizes sao %.2f e %.2f\n", x1, x2);
	}
	return 0;
}

int calculaRaizes2o_Grau(float A, float B, float C, float* X1, float* X2) {
	float delta;
	delta = B*B - 4*A*C;
	if (delta < 0) {
		return 0;	// retorna falso
	}
	*X1 = (-B + sqrt(delta))/(2*A);
	*X2 = (-B - sqrt(delta))/(2*A);
	return 1;
}

