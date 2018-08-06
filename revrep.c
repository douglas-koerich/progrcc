#include <stdlib.h>
#include <stdio.h>

int main() {
	int soma, num_usuario, num;

	/* Solucao ruim: usando while
	printf("Digite o numero-limite: ");
	scanf("%d", &num_usuario);
	// xunxo: num_usuario = 1;

	while (num_usuario % 2 != 0) {
		printf("Voce digitou um numero invalido (impar)!\n");

		printf("Digite o numero-limite: ");
		scanf("%d", &num_usuario);
	}
	*/

	// Solucao melhor: usando do-while
	do {
		printf("Digite o numero-limite: ");
		scanf("%d", &num_usuario);
		if (num_usuario % 2 != 0) {
			printf("Voce digitou um numero invalido (impar)!\n");
		}
		else if (num_usuario < 0) {
			printf("Voce digitou um numero invalido (negativo)!\n");
		}
	}
	while (num_usuario < 0 || num_usuario % 2 != 0);

	/*
	soma = 0;
	num = 0;	 // valor inicial de num eh 0
	*/
	soma = num = 0;

	while (num <= num_usuario) {
		if (num % 3 == 0) {
			// soma = soma + num;
			soma += num;
		}
		// num = num + 1;
		// num += 1;
		++num;
	}

	printf("Soma dos divisiveis por 3: %d.\n", soma);

	return 0;
}

