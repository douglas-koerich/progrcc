#include <stdio.h>
#include <math.h>

int main() {
	float peso, altura, imc;
	printf("Digite seu peso: ");
	scanf("%f", &peso);
	printf("Digite sua altura: ");
	scanf("%f", &altura);
	imc = peso / pow(altura, 2);
	printf("%.2f: ", imc);

	if (imc < 18.5) {
		printf("Abaixo do peso.\n");
	}
	else {
		if (imc < 25) {
			printf("Peso normal.\n");
		}
		else {
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

