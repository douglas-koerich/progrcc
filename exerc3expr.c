#include <stdio.h>

int main() {
	// Leitura dos pontos P1 e P2
	float x1, y1,	// ponto P1
		  x2, y2,	// ponto P2
		  x, y;		// outro ponto

	printf("Digite as coordenadas do primeiro ponto:\n");
	printf("X1? "); scanf("%f", &x1);
	printf("Y1? "); scanf("%f", &y1);

	printf("Agora, digite as coordenadas do segundo ponto:\n");
	printf("X2? "); scanf("%f", &x2);
	printf("Y2? "); scanf("%f", &y2);

	// Variavel de apoio ao calculo
	float a;

	a = (y2-y1)/(x2-x1);	// parenteses sao necessarios para
							// fazer as subtracoes ANTES da divisao

	printf("Digite a ordenada (Y) do ponto cuja abscissa (X) deseja calcular: ");
	scanf("%f", &y);

	// Calculo
	x = (y-y1)/a + x1;

	// Impressao/saida do resultado
	printf("X = %f\n", x);

	return 0;
}

