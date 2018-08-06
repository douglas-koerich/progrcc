#include <stdio.h>

int main(void) {
	int f0 = 0, f1 = 1, fn, fn_1, fn_2, n, contador;

	do {
		printf("Numero do termo de Fibonacci: ");
		scanf("%d", &n);
	} while (n < 0);

	if (n == 0) {
		printf("O termo eh %d.\n", f0);
	}
	else if (n == 1) {
		printf("O termo eh %d.\n", f1);
	}
	else {
		fn_2 = f0;
		fn_1 = f1;
		printf("(Apenas para teste: ");
		for (contador = 2; contador <= n; ++contador) {
			fn = fn_1 + fn_2;	// calcula este termo
			fn_2 = fn_1;		// para o proximo laco, o anterior vira ant-anterior...
			fn_1 = fn;			// ... e o atual vira o anterior
			printf("%d ", fn);
		}
		printf(")\nO termo eh %d.\n", fn);
	}
	return 0;
}

