#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
	float preco, imposto;
	int categoria;
	char situacao;

	printf("Digite o preco: "); scanf("%f", &preco);
	printf("Digite a categoria: "); scanf("%d", &categoria);
	printf("Digite a situacao: "); scanf(" %c", &situacao);

	// Letra a
	if (preco <= 25.0) {
		switch (categoria) {
			case 1:
				preco = preco + (preco * 5/100.0);
				break;

			case 2:
				// preco = preco * (1 + 0.08);
				preco = preco + (preco * 0.08);
				break;

			case 3: 
				preco += preco * 0.10;
				break;

			default:
				printf("Categoria invalida!\n");
				exit(-1);
		}
	}
	else {
		switch (categoria) {
			case 1:
				preco = preco + (preco * 12/100.0);
				break;

			case 2:
				// preco = preco * (1 + 0.15);
				preco = preco + (preco * 0.15);
				break;

			case 3: 
				preco += preco * 0.18;
				break;

			default:
				printf("Categoria invalida!\n");
				exit(-1);
		}
	}
	printf("Novo preco (bruto): %.2f.\n", preco);

	// Letra b
	// imposto = preco * (categoria == 2 || toupper(situacao) == 'R')? 0.05: 0.08;
	if (categoria == 2 || toupper(situacao) == 'R') {	// "pelo menos" = OU
		imposto = preco * 0.05;
	}
	else {
		imposto = preco * .08;
	}
	printf("Imposto: %.2f.\n", imposto);

	// Letra c
	preco += imposto;	// imposto soma, nunca diminui
	printf("Novo preco (liquido): %.2f.\n", preco);

	// Letra d
	if (preco <= 50.0) {
		printf("Barato!\n");
	}
	else {
		if (preco < 120) {
			printf("Normal.\n");
		}
		else {
			printf("Caro...\n");
		}
	}

	return 0;
}
