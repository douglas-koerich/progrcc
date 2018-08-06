#include <stdio.h>

int main(void) {
	float base, receber;
	printf("Digite o salario-base (R$): ");
	scanf("%f", &base);
	receber = base + base * 5 / 100;	// divisao real
	// receber = base * (1 + 5/100);	// divisao inteira!!!
	receber -= base * 0.07;
	printf("O salario a receber eh R$ %.2f.\n", receber);
	return 0;
}

