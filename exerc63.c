#include <stdbool.h>
#include <stdio.h>

void primos(int);

int main(void) {
	int n;

	printf("Digite um numero: ");
	scanf("%d", &n);

	primos(n);

	return 0;
}

void primos(int n) {
	int contador = 1;
	int da_vez = n+1, i;
	bool ehPrimo;
	while (contador <= 10) {
		for (i=2, ehPrimo=true; i<da_vez; ++i) {
			if (da_vez % i == 0) {
				ehPrimo = false;
				break;
			}
		}
		if (ehPrimo == true) {
			printf("%d ", da_vez);
			++contador;
		}
		++da_vez;
	}
	printf("\n");
}

