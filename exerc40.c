#include <stdio.h>

int main() {
	int n;

	do {
		printf("Digite o valor de n: ");
		scanf("%u", &n);
	} while (n <= 0);

	int x;
	float soma;
	
	for (x = 1, soma = 0.0; x <= n; ++x) {
		soma += 1.0 / x;	// uso 1.0 pra forcar uma divisao REAL
	}
	
	// Variantes menos legiveis (e menos usadas)!
	// for (x = 1, soma = 0.0; x <= n; soma += 1.0 / x, ++x) {}
	// for (x = 1, soma = 0.0; x <= n; soma += 1.0 / x++);

	printf("O somatorio da serie eh %f.\n", soma);

	return 0;
}

