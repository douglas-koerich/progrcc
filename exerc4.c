#include <stdio.h>

int main() {
	int numero;

	printf("Digite o numero: ");
	scanf("%d", &numero);

	int milhares, centenas, dezenas, unidades, resto;
	milhares = numero / 1000;	// divisao inteira (var. int / const. int)
	resto = numero % 1000;		// resto da divisao de numero por 1000

	centenas = resto / 100;
	resto = resto % 100;		// substitui resto original pelo novo

	dezenas = resto / 10;
	resto %= 10;				// equivale a: resto = resto % 10;

	unidades = resto;			// unidades = resto / 1;

	printf("%d: %d unidades de milhar, %d centenas, %d dezenas e %d unidades\n", numero, milhares, centenas, dezenas, unidades);

	return 0;
}

