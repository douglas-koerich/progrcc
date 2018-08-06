#include <stdio.h>

int main() {
	// Dado de entrada: n (a e b sao constantes)
	int n;
	const float a = 0.0, b = 1.0;

	// Leitura do valor de n (quantas divisoes/quantos trapezios vai haver
	// entre os valores de a e b)
	printf("Digite o numero de divisoes do intervalo (n): ");
	scanf("%d", &n);
	
	// Calculo do Delta-x
	float delta_x = (b-a)/n;

	// Inicializa valor do somatorio
	float S = 0.0;

	// Laco para calcular e somar as areas de cada trapezio
	int i;
	float Ai, xi, xi_1, yi, yi_1;
	for (i=1, xi_1=a; i<=n; ++i, xi_1=xi) {
		xi = xi_1 + delta_x;
		yi = 1 / (1 + xi*xi);
		yi_1 = 1/ (1 + xi_1*xi_1);
		Ai = ((yi + yi_1) / 2) * delta_x;
		S += Ai;
	}

	// O valor de PI eh obtido pela multiplicacao de S (integral) por 4
	float pi = S * 4;
	printf("Pi = %.10f\n", pi);

	return 0;
}

