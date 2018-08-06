#include <stdlib.h>
#include <stdio.h>

// Vamos apelidar o 'unsigned char' de 'byte'
typedef unsigned char byte;

// Prototipos
byte calcChecksum(size_t, byte[*]);
byte calcChecksumStr(char[*]);

#define TAMANHO	4
#define MAX		100

int main() {
	byte buffer[TAMANHO] = { 100, 101, 102 };
	char string[MAX];

	// Calculando checksum de um pacote de bytes quaisquer
	buffer[TAMANHO-1] = calcChecksum(TAMANHO-1, buffer);
	puts("Conteudo do pacote transmitido:");
	size_t b;
	for (b=0; b<TAMANHO; ++b) {
		printf("%hhu ", buffer[b]);
	}
	putchar('\n');	// para imprimir um caracter (note as aspas simples!)

	// Calculando checksum de uma string
	puts("Digite abaixo uma string:");
	gets(string);
	byte chkString = calcChecksumStr(string);
	printf("O checksum calculado eh %hhu\n", chkString);

	return 0;
}

// O calculo do checksum eh feito somando os codigos binarios
// de cada byte, acumulando-os num byte
byte calcChecksum(size_t tamanho, byte pacote[tamanho]) {
	byte checksum = 0;
	size_t b;
	for (b=0; b<tamanho; ++b) {
		checksum += pacote[b];
	}
	return checksum;
}

byte calcChecksumStr(char string[]) {
	byte checksum = 0;
	int b = 0;
	while (string[b] != '\0') {
		checksum += (byte) string[b++];	// b++: economizando a linha seguinte
		// ++b;
	}
	return checksum;
}

