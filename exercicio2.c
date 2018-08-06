#include <stdio.h>
#include <math.h>

int main() {
	float inicial, final, taxa;
	int meses;

	printf("Digite o valor inicial aplicado: ");
	scanf("%f", &inicial);

	printf("Digite a taxa de juros, em %% a.m.: ");
	scanf("%f", &taxa);

	// Deve converter a taxa percentual para absoluta,
	// i.e. ex: 1,5% a.m. ==> 0,015
	taxa /= 100.0;

	printf("Digite o numero de meses da aplicacao: ");
	scanf("%d", &meses);

	final = inicial * pow((1+taxa), meses);

	printf("O valor final apos o periodo de aplicacao eh %.2f.\n", final);

	return 0;
}

