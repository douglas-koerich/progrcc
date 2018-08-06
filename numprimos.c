#include <stdio.h>

int main() {
	unsigned n=2, i, total, contador = 0;

	printf("Digite quantos primos serao impressos: ");
	scanf("%u", &total);

	while (contador < total) {
		for (i=2;i<n;++i) {
			if (n%i == 0) { // n eh divisivel por i (o 'i' da vez)?
				break;		// interrompe o laco for (nao o while!), nao faz sentido testar outros
			}
		}
		if (i == n) {	// nao saiu por break, saiu porque teste i<n = false
			printf("%d ", n);
			++contador;
		}
		++n;
	}
	printf("\n");
	return 0;
}

