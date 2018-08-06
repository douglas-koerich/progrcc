#include <stdio.h>
#include <math.h>

int main() {
	double peso, altura, imc;

	printf("Digite peso [kg]: "); scanf("%lf", &peso);
	printf("Digite altura [m]: "); scanf("%lf", &altura);

	// imc = peso / (altura * altura);
	imc = peso / pow(altura, 2);

	if (imc < 18.5) {
		printf("Abaixo do peso.\n");
	}
	else {
		// if (imc >= 18.5 && imc < 25) {
		if (imc < 25) {
			printf("Peso normal.\n");
		}
		else {
			// if (imc >= 25 && imc <= 30) {
			if (imc <= 30) {
				printf("Acima do peso.\n");
			}
			else {
				printf("Obeso.\n");
			}
		}
	}

	return 0;
}

