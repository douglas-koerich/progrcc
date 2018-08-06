#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	float preco, bruto;
	int categoria;
	char situacao;

	printf("Digite o preco do produto (R$): ");
	scanf("%f", &preco);
	printf("Digite a categoria (1,2,3): ");
	scanf("%d", &categoria);
	printf("Digite a situacao (R,N): ");
	scanf(" %c", &situacao);

	// Letra (a)
	switch (categoria) {
		case 1:
			if (preco <= 25.0) {
				bruto = preco + preco * 5/100;
			}
			else {
				bruto = preco + preco * 0.12;
			}
			break;

		case 2:
			if (preco <= 25.0) {
				bruto = preco * (1 + 0.08);
			}
			else {
				bruto = preco * 1.15;
			}
			break;

		case 3:
			bruto = preco * ((preco <= 25.0)? 1.10 : 1.18);
			break;

		default:
			printf("INVALIDO\n");
			return EXIT_FAILURE;
	}
	printf("O preco bruto sera R$ %.2f.\n", bruto);

	// Letra (b)
	float imposto;
	if (categoria == 2 || toupper(situacao) == 'R') {
		imposto = bruto * 0.05;
	}
	else {
		imposto = bruto * 0.08;
	}
	printf("O imposto cobrado sera R$ %.2f.\n", imposto);

	// Letra (c)
	float liquido = bruto + imposto;
	printf("O preco final sera R$ %.2f.\n", liquido);

	// Letra (d)
	if (liquido <= 50.0) {
		printf("Barato.\n");
	}
	else if (liquido >= 120.0) {
		printf("Caro.\n");
	}
	else {
		printf("Normal.\n");
	}
	return EXIT_SUCCESS;
}

