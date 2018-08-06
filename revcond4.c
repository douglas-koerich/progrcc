#include <stdio.h>
#include <stdlib.h>

int main() {
	int codproduto, codpais;
	float peso, pesog, preco, imposto, total;

	printf("Digite o codigo do produto (1-10): ");
	scanf("%d", &codproduto);
	printf("Digite o peso do produto [kg]: ");
	scanf("%f", &peso);
	printf("Digite o pais de origem (1-3): ");
	scanf("%d", &codpais);

	pesog = peso*1000;

	if (codproduto >= 1 && codproduto <= 4) {
		preco = pesog * 10;
	}
	else {
		if (codproduto >= 5 && codproduto <= 7) {
			preco = pesog * 25;
		}
		else {
			if (codproduto >= 8 && codproduto <= 10) {
				preco = pesog * 35;
			}
			else {
				printf("Codigo do produto eh invalido!\n");
				exit(-1);
			}
		}
	}

	switch (codpais) {
		case 1:
			imposto = preco * 0;
			break;

		case 2:
			imposto = preco * 15 / 100;
			break;

		case 3:
			imposto = preco * 0.25;
			break;

		default:
			printf("Codigo do pais eh invalido!\n");
			exit(-1);
	}

	total = preco + imposto;

	printf("Peso em gramas = %f.\n", /*peso*1000*/ pesog);
	printf("Preco total = R$ %.2f.\nImposto = R$ %.2f.\nValor total = R$ %.2f.\n", preco, imposto, total);

	return 0;
}

