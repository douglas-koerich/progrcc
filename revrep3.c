#include <stdio.h>
#include <math.h>

// Exercicio 42

int main() {
	int num_termos, termo;
	float S, pi, base_denominador;

	do {
		printf("Digite o numero de termos da serie: ");
		scanf("%d", &num_termos);
	}
	while (num_termos <= 0 || num_termos > 50);

	/* Preparacao do laco se estivessemos usando while
	termo = 1;
	S = 0.0;
	*/

	for (termo = 1, S = 0.0, base_denominador = 1; termo <= num_termos; ++termo, base_denominador += 2) {

		/* outro jeito de fazer a soma do termo (mais complicado)
		S += pow(-1, termo+1) * 1/pow(base_denominador, 3);
		*/

		if (termo % 2 == 0) {
			S -= 1/pow(base_denominador, 3);
		}
		else {
			S += 1/pow(base_denominador, 3);
		}

		/* Se estivessemos usando while
		++termo;
		base_denominador += 2;
		*/
	}

	pi = pow(S*32, 1.0/3);	// se usar 1/3 vai ficar elevado a 0 (div. inteira)

	printf("pi = %.4f.\n", pi);

	return 0;
}

