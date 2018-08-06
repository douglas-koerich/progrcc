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

	switch (sexo) {
		case 'M':
		case 'm':
			peso = 72.7*altura - 58;
			break;

		case 'F': case 'f':
			peso = 62.1*altura - 44.7;
			break;

		default:
			printf("Sexo invalido!\n");
			exit(-1);
	}

	printf("Peso ideal [kg]: %.2f\n", peso);
	return 0;
}

