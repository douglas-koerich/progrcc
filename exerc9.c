#include <stdio.h>
#include <math.h>

int main() {
	float Vf, Vi, i;
	int N;

	// Dados de entrada:
	printf("Valor inicial (R$)? "); scanf("%f", &Vi);
	printf("Numero de periodos (meses)? "); scanf("%d", &N);
	printf("Taxa de juros (%%)? "); scanf("%f", &i);

	Vf = Vi * pow(1 + i/100, N);

	printf("Valor final (R$): %.2f\n", Vf);

	return 0;
}

