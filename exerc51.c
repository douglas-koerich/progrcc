#include <stdio.h>
#include <math.h>

int main(void) {
	float x, mod_x, tolerancia, f_x_original, f_x_serie;
	int contador_termos, expoente;

	do {
		printf("Digite o valor de x: ");
		scanf("%f", &x);
		// mod_x = fabs(x);
		/* if (x < 0.0) {
		 *  mod_x = -x;
		 * }
		 * else {
		 *  mod_x = x;
		 * }
		 */
		mod_x = x < 0.0? -x: x;
	} while (mod_x >= 1.0);

	// Deveria tambem checar o valor da tolerancia...
	printf("Digite a tolerancia: ");
	scanf("%f", &tolerancia);

	f_x_original = 1.0 / (1.0 - x);
	f_x_serie = 1.0;
	contador_termos = expoente = 1;	// ambas recebem o valor 1

	while (fabsf(f_x_original - f_x_serie) >= tolerancia) {
		/*
		f_x_serie = f_x_serie + pow(x, expoente);
		++expoente;
		*/
		f_x_serie += pow(x, expoente++);	// incrementa DEPOIS!
		++contador_termos;
		// f_x_serie += pow(x, contador_termos++);	// mais confuso
	}
	printf("O numero de termos necessarios eh %d.\n", contador_termos);
	return 0;
}

