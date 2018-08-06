#include <stdio.h>
#include <stdio_ext.h>	// para usar __fpurge
#include <string.h>

#define MAX_STRING	100

void inverte(char [*], char [*]); // nao precisa passar o tamanho porque
								  // existem marcadores de fim em ambos os
								  // vetores (sao os terminadores nulos!)

int main() {
	// Declaracao da variavel string
	char string[MAX_STRING];

	// Leitura de uma string do teclado
	printf("Digite uma string qualquer: ");
	__fpurge(stdin);	// "limpa" o buffer do teclado no LINUX
	gets(string);		// com buffer limpo, le uma string do teclado

	// Declaracao de uma outra string com tamanho exato para conter
	// a primeira invertida
	char outra[strlen(string)+1];	// strlen() NAO CONTA o terminador nulo

	// Chama um procedimento para inverter 'string' em 'outra'
	inverte(string, outra);
	
	// Imprime a string invertida
	printf("String invertida: %s\n", outra);
	
	return 0;
}

void inverte(char original[], char invertida[]) {
	// Percorre a string original do inicio para o fim, copiando cada
	// caracter para a string invertida, do fim para o inicio
	int ind_orig = 0,
		ind_invert = strlen(original)-1;

	// Comecamos colocando o terminador nulo no fim de 'outra'
	while (original[ind_orig] != '\0') { // enquanto nao chega ao fim...
		invertida[ind_invert--] = original[ind_orig++];
	}
	invertida[strlen(original)] = '\0';
}

