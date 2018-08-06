#include <stdio.h>
#include <ctype.h>

#define MAX_CARACTERES	100	// numero maximo de caracteres validos

int main() {
	char nome[MAX_CARACTERES+1]; // reserva adicional para o termin. nulo

	// Nao aceita nomes que comecem com letra minuscula
	do {
		printf("Digite seu nome: "); // usando uma constante string
		gets(nome);
		// scanf(" %s", nome);			 // sem o & na frente!!!
	} while (islower(nome[0]));		 // cada elemento da variavel eh um char

	printf("Ola, %s! Bora tomar um cafeh?!\n", nome);

	puts("O nome da pessoa eh ");	// nao consegue usar com %s!!
	puts(nome);

	// Para imprimir sem o \n automatico do puts...
	printf("O nome da pessoa eh ");
	//printf(nome);	// sem salto de linha
	printf("%s\n", nome);	// com salto de linha

	return 0;
}

