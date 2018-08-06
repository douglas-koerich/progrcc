#include <stdio.h>

int main(void) {
	int valor;
	printf("Valor? ");
	scanf("%d", &valor);

	int notas50 = valor / 50;
	valor %= 50;
	int notas10 = valor / 10;
	valor %= 10;
	int notas1 = valor;	// qq num dividido por 1 eh ele mesmo (valor/1)

	printf("Sao %d notas de $50, %d notas de $10 e %d notas de $1.\n",
		   notas50, notas10, notas1);
	return 0;
}

