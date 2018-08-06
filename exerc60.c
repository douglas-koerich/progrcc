#include <stdio.h>
#include <math.h>

// DECLARACAO da funcao: "prototipo" da funcao
int calculaSomaInteiros(float, float);

int main(void) {
	float num1, num2;
	int soma;

	printf("Primeiro numero: ");
	scanf("%f", &num1);
	printf("Segundo numero: ");
	scanf("%f", &num2);

	soma = calculaSomaInteiros(num1, num2);
	printf("A soma dos inteiros entre %f e %f eh %d.\n", num1, num2, soma);

	return 0;
}

// DEFINICAO da funcao
int calculaSomaInteiros(float n1, float n2) {
	int s = 0;	// inicializa o somatorio
	int i = ceil(n1), f = n2;

	if (n2 < n1) {
		return 0;
	}
	while (i <= f) {
		s += i;
		++i;
	}
	return s;
}

