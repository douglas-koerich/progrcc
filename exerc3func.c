#include <stdio.h>
#include <math.h>

float somaTermos(unsigned);

int main() {
	unsigned numero;
	float soma;

	printf("Digite o numero de termos para computar: ");
	scanf("%u", &numero);

	soma = somaTermos(numero);

	printf("O somatorio resultou em %.3f\n", soma);

	return 0;
}

float somaTermos(unsigned N) {
	unsigned n;		// variavel de controle do laco
	float S = 0;	// inicializacao com o elemento neutro da soma
	for (n=1; n<=N; ++n) {
		float termo = (pow(n,2) + 1) / (n+3);
		S += termo;
	}
	return S;
}

