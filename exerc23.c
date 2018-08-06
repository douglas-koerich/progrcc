#include <stdio.h>
#include <stdbool.h>

int main() {
	int num;
	printf("Digite um numero: ");
	scanf("%d", &num);

	int resto = num % 2;

	/* Solucao 1: mais clara
	if (!resto) {	// <=> if (!(resto != 0)) <=> if (resto == 0)
		printf("O numero eh PAR.\n");
	}
	else {
		printf("O numero eh IMPAR.\n");
	} */

	/* Solucao 2: mais elaborada 
	printf("O numero eh "); 	// para ser completada a seguir
	bool ehPar = resto == 0;	// ehPar eh uma variavel logica/booleana
	if (ehPar) {
		printf("PAR.\n");
	}
	else {
		printf("IMPAR.\n");
	}
	*/

	/* Solucao 2,5: economizando, usando o operador ternario!
	printf("O numero eh ");
	bool ehPar = resto == 0;
	printf(ehPar? "PAR.\n": "IMPAR.\n");
	*/

	// Solucao 3: Em uma linha, com o operador ternario dentro do printf
	printf("O numero eh %s.\n", resto == 0? "PAR": "IMPAR");
	return 0;
}

