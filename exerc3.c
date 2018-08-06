#include <stdio.h>

// Prototipo de funcao ("declaracao" da funcao para o compilador)
int calculaFatorial(int);

int main() {
	float Y, P;
	int N, i, fatorial;

	printf("Qual o valor de Y na expressao? ");
	scanf("%f", &Y);
	printf("Quantos termos (N) deseja utilizar? ");
	scanf("%d", &N);

	for (i=1, P=1.0; i<=N; ++i) {
		/*
		for (n=(i-1), fatorial=1; n>=1; --n) {
			fatorial *= n;
		}
		*/
		fatorial = calculaFatorial(i-1);
		P *= Y / fatorial;
		// P *= Y / calculaFatorial(i-1);
	}

	printf("O produtorio (P) resultou %f\n", P);

	return 0;
}

int calculaFatorial(int x) {
	int n, fat;
	if (x < 0) {
		return 0;	// sai imediatamente da funcao com retorno 0
	}
	for (n=x, fat=1; n>=1; --n) {
		fat *= n;
	}
	return fat;
}
