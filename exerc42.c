#include <stdio.h>
#include <math.h>

int main(void) {
	unsigned num_termos, termo, base_denominador;
	float S, pi, parcela;

	do {
		printf("Digite o numero de termos: ");
		scanf("%u", &num_termos);
	} while (num_termos > 50);

	for (termo = 1, S = 0.0, base_denominador = 1; termo <= num_termos;
		 ++termo, base_denominador += 2) {
		parcela = 1 / pow (base_denominador, 3);
		if (termo % 2 == 0) {	// termo de ordem par
			S -= parcela;
		}
		else {
			S += parcela;
		}
	}
	pi = pow(S*32, 1/3.0);	// cuidado! deve ser uma divisao real!
	printf("Pi aproximado = %f.\n", pi);

	return 0;
}

