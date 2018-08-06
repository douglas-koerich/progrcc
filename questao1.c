#include <stdio.h>

int main(void) {
	float fixo, bruto, liquido, inss, comissao, imposto = 0.0;
	int num_ate42, num_acima42;

	printf("Digite o salario fixo: ");
	scanf("%f", &fixo);
	inss = fixo * 0.08;	// inss = fixo * 8 / 100;	(ufa, fixo eh float!)
	printf("Quantos televisores ate 42\"? ");
	scanf("%d", &num_ate42);
	printf("Quantos televisores acima de 42\"? ");
	scanf("%d", &num_acima42);

	if (num_acima42 >= 10) {
		comissao = 150 * num_acima42;
	}
	else {
		comissao = 30 * num_acima42;
	}
	// comissao = num_acima42 * (num_acima42 >= 10? 150: 30);

	if (num_ate42 >= 20) {
		comissao += 75 * num_ate42;
	}
	else {
		comissao += 15 * num_ate42;
	}
	// comissao += num_ate42 * (num_ate42 >= 20? 75: 15);
	
	bruto = fixo + comissao;
	liquido = bruto - inss;

	if (liquido >= 1500.0) {
		imposto = liquido * .15;
	}
	liquido = liquido - imposto;	// liquido -= imposto;

	printf("Bruto = %.2f, liquido = %.2f\n", bruto, liquido);

	return 0;
}

