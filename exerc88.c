#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned int calculaChecksum(unsigned char*, int);

int main(void) {
	srand((unsigned) time(0));

	int tamanho;
	printf("Quantos bytes tem a area de memoria? ");
	scanf("%d", &tamanho);

	// Usamos unsigned porque do byte nao queremos saber sobre o bit de sinal
	unsigned char* memoria = (unsigned char*) malloc(tamanho*sizeof(unsigned char));

	int i;
	for (i=0; i<tamanho; ++i) {
		memoria[i] = rand() % 0x100;	// randomicos de 0h a FFh
		printf("%hhx ", memoria[i]);	// %hhx para imprimir char como hex
	}
	putchar('\n');

	// Se o checksum eh uma operacao binaria sobre bytes SEM sinal, entao
	// deve ser tambem ele um inteiro SEM sinal
	unsigned int chk = calculaChecksum(memoria, tamanho);

	printf("O checksum da memoria eh %x.\n", chk);	// imprime em hexa

	free(memoria);

	return EXIT_SUCCESS;
}

unsigned int calculaChecksum(unsigned char* inicio_memoria, int extensao) {
	unsigned int checksum = 0, i;
	// unsigned char* paux;

	for (i=0 /*, paux = inicio_memoria */; i<extensao; ++i /*, ++paux */) {
		// byte_da_vez = *paux;
		unsigned char byte_da_vez = *(inicio_memoria+i);
		checksum = checksum | byte_da_vez;
	}
	return checksum;
}

