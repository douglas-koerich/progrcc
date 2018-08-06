#include <stdio.h>

int main() {
	int codigo, pais;
	float peso;

	printf("Digite o codigo: "); scanf("%d", &codigo);
	printf("Digite o peso: "); scanf("%f", &peso);
	printf("Digite o pais de origem: "); scanf("%d", &pais);

	// Letra a
	float gramas = peso * 1000;
	printf("Peso em gramas: %.0f\n", gramas);

	// Letra b
	float preco;
	if (codigo >= 1 && codigo <= 4) {
		preco = gramas * 10;
	}
	else if (codigo >= 5 && codigo <= 7) {
		preco = gramas * 25;
	}
	else {
		preco = gramas * 35;
	}
	printf("Preco (antes do imposto): $%.2f\n", preco);

	// Letra c
	float imposto;
	switch (pais) {
		case 2: imposto = preco * 15 / 100;
				break;

		case 3: imposto = preco * .25;
				break;

		default: imposto = 0;
	}
	printf("Imposto: $%.2f\n", imposto);

	// Letra d
	printf("Total: $%.2f\n", preco + imposto);

	return 0;
}

