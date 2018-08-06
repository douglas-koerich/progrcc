#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>

int main() {
	float altura, peso;
	char sexo;

	printf("Digite o sexo (M/F): ");
	scanf(" %c", &sexo);
	// sexo = toupper(sexo);	
	printf("Digite a altura [m]: ");
	scanf("%f", &altura);

	if (sexo == 'M' || sexo == 'm') {
		peso = 72.7*altura - 58;
	}
	else {
		if (sexo == 'F' || sexo == 'f') {
			peso = 62.1*altura - 44.7;
		}
		else {
			printf("Sexo invalido!\n");
			exit(-1);
		}
	}

	// peso = (sexo == 'M' || sexo == 'm')? (72.7*altura - 58): (62.1*altura - 44.7);

	printf("Peso ideal [kg]: %.2f\n", peso);
	return 0;
}

