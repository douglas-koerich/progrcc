#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Prototipo ("declaracao") da funcao
float funcao(unsigned);

int main() {
	unsigned entrada;
	float saida;

	printf("Digite o numero de entrada: ");
	scanf("%u", &entrada);

	saida = funcao(entrada);

	printf("A soma resultante eh: %.3f\n", saida);

	return EXIT_SUCCESS;	// = 0
}

float funcao(unsigned N) {
	float S;	// variavel de retorno da funcao
	unsigned n;

	for (n=1, S=0.0; n<=N; ++n) {
		S += (pow(n, 2) + 1)/(n + 3);
	}

	return S;
}

