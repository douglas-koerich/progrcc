#include <stdio.h>

int main() {
	// Dados de entrada
	int dia_da_semana;	// 1=dom, 2=seg, 3=ter, ...
	int idade;
	float v;

	// Dados de saida
	float valor_a_pagar;

	// Leitura dos dados de entrada
	printf("Informe o dia da semana (1-7): ");
	scanf("%d", &dia_da_semana);

	printf("Informe a idade do espectador: ");
	scanf("%d", &idade);

	printf("Qual eh o valor do preco-base? ");
	scanf("%f", &v);

	// Iniciamos definindo o valor a pagar como o preco "cheio"
	valor_a_pagar = v;

	// Aplica desconto da idade
	if (idade < 14) {
		/*
		valor_a_pagar = valor_a_pagar * 50 / 100;	// valor_a_pagar * 0.5;
		*/
		valor_a_pagar *= 0.5;
	}
	// Aplica desconto do dia da semana
	if (dia_da_semana == 3) {
		valor_a_pagar *= 0.5;
	}

	// Imprime o dado de saida
	printf("Valor a pagar: %.2f\n", valor_a_pagar);

	return 0;
}

