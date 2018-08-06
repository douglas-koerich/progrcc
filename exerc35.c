#include <stdio.h>

int main(void) {
	int angulo, reduzido, voltas;

	printf("Digite o angulo (em graus): ");
	scanf("%d", &angulo);

	voltas = angulo / 360;
	reduzido = angulo % 360;

	if ((reduzido > 0 && reduzido <= 90) ||
		(reduzido > -360 && reduzido <= -270)) {
		printf("Primeiro quadrante.\n");
	}
	else {	// segundo, terceiro ou quarto
		if ((reduzido > 90 && reduzido <= 180) ||
			(reduzido > -270 && reduzido <= -180)) {
			printf("Segundo quadrante.\n");
		}
		else {	// terceiro ou quarto
			if ((reduzido > 180 && reduzido <= 270) ||
				(reduzido > -180 && reduzido <= -90)) {
				printf("Terceiro quadrante.\n");
			}
			else { // soh restou o quarto
				printf("Quarto quadrante.\n");
			}
		}
	}
	/* Testando soh angulos positivos...
	if (reduzido > 0 && reduzido <= 90) {
		printf("Primeiro quadrante.\n");
	}
	else if (reduzido <= 180) {
		printf("Segundo quadrante.\n");
	}
	else if (reduzido <= 270) {
		printf("Terceiro quadrante.\n");
	else {
		printf("Quarto quadrante.\n");
	}
	*/
	if (angulo < 0) {
		printf("Sentido horario, %d voltas.\n", -voltas);
	}
	else {
		printf("Sentido anti-horario, %d voltas.\n", voltas);
	}
	if (angulo > 360 || angulo < -360) {
		printf("Angulo reduzido = %d graus.\n", reduzido);
	}
	return 0;
}

