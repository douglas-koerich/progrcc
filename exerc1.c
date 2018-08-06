#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int x, y, auxiliar_de_troca;

	printf("Digite o primeiro numero: ");
	scanf("%d", &x);
	printf("Agora, digite o segundo: ");
	scanf("%d", &y);

	printf("Variaveis antes da troca: x = %d, y = %d.\n", x, y);
	auxiliar_de_troca = x;
	x = y;
	y = x;
	y = auxiliar_de_troca;
	printf("Variaveis depois da troca: x = %d, y = %d.\n", x, y);

	return EXIT_SUCCESS;
}

