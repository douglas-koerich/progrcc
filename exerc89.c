#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_DIGITOS_CONTA	5

char digito_verificador(char* conta) {	// conta = "25678"
	int numconta = atoi(conta);		// numconta = 25678
	int backup = numconta;

	int dezmilhar = numconta / 10000;	// dezmilhar = 2
	numconta = numconta % 10000;		// numconta = 5678
	int unimilhar = numconta / 1000;	// unimilhar = 5
	numconta = numconta % 1000;			// numconta = 678
	int centena = numconta / 100;		// centena = 6
	numconta %= 100;					// numconta = 78
	int dezena = numconta / 10;			// dezena = 7
	int unidade = numconta % 10;		// unidade = 8

	int invertido = unidade * 10000 + dezena * 1000 +
					centena * 100 + unimilhar * 10 + dezmilhar;
	// invertido = 87652
	
	int soma = backup + invertido;

	int centmilhar = soma / 100000;
	soma %= 100000;
	dezmilhar = soma / 10000;
	soma %= 10000;
	unimilhar = soma / 1000;
	soma %= 1000;
	centena = soma / 100;
	soma %= 100;
	dezena = soma / 10;
	unidade = soma % 10;

	int mult = centmilhar*1 + dezmilhar*2 + unimilhar*3 +
			   centena*4 + dezena*5 + unidade*6;

	int digito = mult % 10;

	return digito + '0';
}

int main(int argc, char* argv[]) {
	if (argc < 3) {
		puts("Numero invalido de parametros, abortado!");
		printf("Use: %s <num-conta> <digito>\n", argv[0]);
		return -1;	// return EXIT_FAILURE
	}
	if (strlen(argv[1]) != NUM_DIGITOS_CONTA) {
		puts("Numero da conta invalido!");
		return -1;
	}
	int i;
	for (i=0; i<NUM_DIGITOS_CONTA; ++i) {
		if (!isdigit(argv[1][i])) {
			puts("Conta com caracteres nao-numericos!");
			return -1;
		}
	}
	if (!isdigit(argv[2][0])) {
		puts("Digito verificador nao eh numero!");
		return -1;
	}
	char digito_correto = digito_verificador(argv[1]);
	if (digito_correto == argv[2][0]) {
		puts("Digito OK!");
	}
	else {
		puts("Digito nao confere!");
	}
	return 0;
}

