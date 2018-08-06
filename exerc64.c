#include <stdio.h>
#include <math.h>

int calculaRaizes(float A, float B, float C, float* X1, float* X2) {
	float delta = pow(B, 2) - 4*A*C;
	if (delta < 0) {
		return 0;	// retorna falso (X1 e X2 nao sao alterados!)
	}
	else {
		*X1 = (-B + sqrt(delta))/(2*A);	// retorna as raizes "indiretamente"
		*X2 = (-B - sqrt(delta))/(2*A); // atraves dos enderecos das mesmas
		return 1;
	}
}

int main() {
	float a, b, c;	// coeficientes da equacao do segundo grau: ax^2+bx+c=0

	printf("Digite o termo de grau 2: "); scanf("%f", &a);
	printf("Digite o termo de grau 1: "); scanf("%f", &b);
	printf("Digite o termo independente (grau 0): "); scanf("%f", &c);

	float x1, x2;
	int temRaizesReais = calculaRaizes(a, b, c, &x1, &x2);
	if (temRaizesReais == 0) { 	// retornou falso? (0 eh falso em C!)
		puts("Nao ha raizes reais!");
	}
	else {
		printf("As raizes sao reais e valem: x1=%.2f e x2=%.2f\n", x1, x2);
	}

	/*
	float delta = pow(b, 2) - 4*a*c;
	if (delta < 0) {
		puts("Nao ha raizes reais!");
	}
	else {
		float x1 = (-b + sqrt(delta))/(2*a),
			  x2 = (-b - sqrt(delta))/(2*a);
		printf("As raizes sao reais e valem: x1=%.2f e x2=%.2f\n", x1, x2);
	}
	*/
	return 0;
}

