#include <stdio.h>

void imprimeSerieFibonacci(int n) {	// void pq nao retorna nada!
	if (n <= 0) {
		return;
	}
	int fn_2 = 0, fn_1 = 1;
	if (n >= 1) {
		printf("%d ", fn_2);
	}
	if (n >= 2) {
		printf("%d ", fn_1);
	}
	if (n > 2) {
		int fn, termo;
		for (termo = 3; termo <= n; ++termo) {
			fn = fn_1 + fn_2;
			printf("%d ", fn);
			fn_2 = fn_1;
			fn_1 = fn;
		}
	}
	printf("\n");
}

int main(void) {
	int num_termos;

	printf("Quantos termos deseja imprimir? ");
	scanf("%d", &num_termos);

	imprimeSerieFibonacci(num_termos);

	return 0;
}

