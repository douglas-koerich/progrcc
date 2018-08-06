#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM_NUM_CONTA	5

char calculaDigito(char[*]);
void inverte(char[*], char[*]);

int main() {
	char conta[TAM_NUM_CONTA+1];

	bool sohNumeros;
	do {
		printf("Digite o numero da conta: ");
		gets(conta);

		sohNumeros = true;
		int i=0;
		while (conta[i] != '\0') {
			if (!isdigit(conta[i])) {
				sohNumeros = false;
				break;	// interrompe o while (conta[i]...
			}
			++i;
		}
	} while (sohNumeros == false);

	char digito_verificador = calculaDigito(conta);

	printf("O numero de conta final eh %s-%c\n", conta, digito_verificador);
	return 0;
}

char calculaDigito(char num_conta[]) {
	char digito;
	char invertida[TAM_NUM_CONTA+1];

	// Letra (a)
	inverte(num_conta, invertida);
	
	int num_conta_i = atoi(num_conta);
	int invertida_i = atoi(invertida);

	int soma = num_conta_i + invertida_i;

	char soma_s[TAM_NUM_CONTA*2];
	sprintf(soma_s, "%d", soma);

	// Letra (b)
	int somatorio = 0, posicao;
	for (posicao = 0; soma_s[posicao] != '\0'; ++posicao) {
		// 'Algarismo' - '0' resulta no numero correspondente
		somatorio += (posicao+1) * (soma_s[posicao] - '0');
	}

	// Letra (c)
	digito = (somatorio % 10) + '0';

	return digito;
}

void inverte(char original[], char invertida[]) {
	int inc, dec = 0;
	dec = strlen(original);
	for (--dec, inc=0; dec>=0; --dec, ++inc) {
		invertida[inc] = original[dec];
	}
	invertida[inc] = '\0';
}

