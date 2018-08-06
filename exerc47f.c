#include <stdio.h>

void imprimePerfeitos(int);

int main(void) {
	int num;

	printf("Quantos numeros perfeitos serao gerados? ");
	scanf("%d", &num);

	imprimePerfeitos(num);

	return 0;
}

void imprimePerfeitos(int N) {
	int contador = 1, n = 1;	// comeca procura pelos perfeitos com 1
	while (contador <= N) {
		int d, soma = 0;		// inicializa soma para este valor de n
		for (d = n-1; d >= 1; --d) {	// soma divisores menores que n
			if (n % d == 0) {	// d eh divisor de n
				soma += d;		// entao soma d
			}
		}
		printf("%d", n);
		if (soma == n) {		// soma bateu com n?
			printf("\n");
			++contador;			// achei mais um perfeito
		}
		else {
			printf("\r");
		}
		fflush(stdout);
		++n;					// incrementa, proximo pode ser perfeito
	}
}

