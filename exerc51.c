#include <stdio.h>
#include <math.h>

int main() {
	float f_x_original, f_x_serie, x, erro;

	printf("Digite o erro (tolerancia) maximo: ");
	scanf("%f", &erro);	// no enunciado, seria o 10^-1

	do {
		printf("Digite o valor de x: ");
		scanf("%f", &x);
	} while (fabs(x) >= 1.0);

	f_x_original = 1 / ( 1 - x);

	int termos = 1;	// inicializa contador com 1 (porque vamos ja contar
					// o primeiro termo)
	f_x_serie = 1;	// ja com o primeiro termo

	while (fabs(f_x_original - f_x_serie) >= erro) {
		f_x_serie += pow(x, termos);
		++termos;
	}

	printf("O numero de termos necessarios foi %d.\n", termos);

	return 0;
}
