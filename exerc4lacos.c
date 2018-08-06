#include <stdio.h>

int main() {
	unsigned n, i;

	printf("Digite um numero para teste: ");
	scanf("%u", &n);

	for (i=2;i<n;++i) {
		if (n%i == 0) { // n eh divisivel por i (o 'i' da vez)?
			break;		// interrompe o laco for (nao o while!), nao faz sentido testar outros
		}
	}
	if (i == n) {	// nao saiu por break, saiu porque teste i<n = false
		printf("O numero eh primo!\n");
	}
	else {
		printf("O numero NAO eh primo!\n");
	}
	return 0;
}

