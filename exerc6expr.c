#include <stdio.h>

int main() {
	float r1, r2, theta1, theta2;

	// Leitura dos dados de entrada (Z1 e Z2)
	printf("Digite o valor do primeiro modulo (r1): ");
	scanf("%f", &r1);
	printf("Digite o valor do primeiro argumento (theta1): ");
	scanf("%f", &theta1);
	
	printf("Digite o valor do segundo modulo (r2): ");
	scanf("%f", &r2);
	printf("Digite o valor do segundo argumento (theta2): ");
	scanf("%f", &theta2);

	printf("Z1 = r1*e^(i*theta1) = %f*e^(i*%f)\n", r1, theta1);
	printf("Z2 = r2*e^(i*theta2) = %f*e^(i*%f)\n", r2, theta2);

	float aux1, aux2;

	// Calculo da multiplicacao
	aux1 = r1 * r2;
	aux2 = theta1 + theta2;
	printf("Z1 x Z2 = %f*e^(i*%f)\n", aux1, aux2);

	// Calculo da divisao
	aux1 = r1 / r2;
	aux2 = theta1 - theta2;
	printf("Z1 / Z2 = %f*e^(i*%f)\n", aux1, aux2);

	return 0;
}

