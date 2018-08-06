#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool testaPalindroma(char[*]);	// nao precisa de um parametro para passar
								// o tamanho porque possui o termin. nulo

#define MAX_TAMANHO	30

int main() {
	char var_string[MAX_TAMANHO];

	do {
		printf("Digite uma palavra: ");
		gets(var_string);
	} while (strlen(var_string) == 0);			// enquanto string vazia
	// } while (strcmp(var_string, "") == 0);	// outro jeito de testar
	// } while (var_string[0] == '\0');			// mais um jeito...
	
	bool ehPalindroma = testaPalindroma(var_string);

	// if (ehPalindroma == true) {
	if (ehPalindroma) {
		puts("A palavra eh palindroma!");
	}
	else {
		puts("A palavra NAO eh palindroma!");
	}

	return 0;
}

#define MAX_FUNCAO	200

bool testaPalindroma(char string[]) {
	char invertida[MAX_FUNCAO+1];

	// Verificacao de seguranca para nao "estourar" o vetor 'invertida'
	if (strlen(string) > MAX_FUNCAO) {
		puts("Nao pode inverter a string recebida!");
		return false;
	}
	int inc, dec = 0;

	// Laco para procurar o indice que aponta para o terminador nulo
	/*
	while (string[dec] != '\0') {
		++dec;
	}
	*/
	dec = strlen(string);
	for (--dec, inc=0; dec>=0; --dec, ++inc) {
		invertida[inc] = string[dec];
	}
	// Ao sair do laco (porque dec ficou igual a -1), inc esta na posicao
	// seguinte ao ultimo copiado (porque foi incrementado); nesta posicao
	// colocamos o terminador nulo manualmente
	invertida[inc] = '\0';

	// Testa se a original eh igual a invertida
	/*
	if (strcmp(string, invertida) == 0) {
		return true;
	}
	else {
		return false;
	}
	*/
	// return strcmp(string, invertida) == 0;
	return !strcmp(string, invertida);	// usa 0 como 'falso' e diferente
										// de zero como 'verdadeiro' ->
										// dai faz a inversao
}

