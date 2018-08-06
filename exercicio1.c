#include <stdio.h>

int main() {
	int horas_normais, horas_extras;
	float valor_hora, salario;

	printf("Digite o valor da hora trabalhada, em R$: ");
	scanf("%f", &valor_hora);

	printf("Digite o numero de horas normais: ");
	scanf("%d", &horas_normais);

	printf("Digite o numero de horas extras: ");
	scanf("%d", &horas_extras);

	// Hora extra paga 75% a mais, ou seja, o valor unitario eh multiplicado
	// por 1.75
	salario = horas_normais * valor_hora + horas_extras * valor_hora * 1.75;

	printf("O salario total eh R$ %.2f.\n", salario);

	return 0;
}

