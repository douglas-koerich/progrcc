#include <stdio.h>
#include <ctype.h>

// inicio
int main(void) {
	// declare altura, peso : real
	float altura, peso;
	// declare sexo : caracter
	char sexo;

	// leia sexo, altura
	printf("Digite a altura: ");
	scanf("%f", &altura);	
	printf("Digite o sexo da pessoa (M/F): ");
	scanf(" %c", &sexo);	// espaco para eliminar o <enter> anterior
	
	// se sexo = 'M' entao
	// if (sexo == 'M' || sexo == 'm') {
	sexo = toupper(sexo);
	if (sexo == 'M') {
		// peso <- 72.7 * altura - 58
		peso = 72.7 * altura - 58;
	}
	// senao
	else {
		// peso <- 62.1 * altura - 44.7
		peso = 62.1 * altura - 44.7;
	}
	// fim-se
	// peso = (sexo == 'M')? (72.7 * altura - 58) : (62.1 * altura - 44.7);
	
	// escreva peso
	printf("O peso ideal da pessoa eh %.1f.\n", peso);
	
	return 0;
// fim
}
