#include <stdio.h>

int main() {
	int primeiro;
	printf("Digite o primeiro numero: ");
	scanf("%d", &primeiro);

	int segundo;
	do {
		printf("Digite o segundo numero: ");
		scanf("%d", &segundo);
	} while (segundo < primeiro);

	int terceiro;
	printf("Digite o terceiro numero: ");
	scanf("%d", &terceiro);

	/*
	int contador = primeiro;		// "... desde o primeiro ..."
	while (contador <= segundo)	{	// "... ateh [inclusive] o segundo ..."
		printf("%d ", contador);
		contador += terceiro;		// contador = contador + terceiro
	}
	*/
	int contador;
	for (contador = primeiro; contador <= segundo; contador += terceiro) {
		printf("%d ", contador);
	}

	printf("\n");
	return 0;
}

