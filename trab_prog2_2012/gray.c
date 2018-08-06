#include "gray.h"

#define MSB	0x80

int bin2gray(FILE* in, FILE* out) {
	while (!feof(in)) {
		char b = fgetc(in);
		if (b == EOF) {
			if (ferror(in)) {
				puts(">>> Erro ao ler o arquivo de entrada! <<<");
				return -1;
			}
		}
		else {
			char g, bit_b, mascara;
			g = bit_b = b & MSB;
			mascara = MSB >> 1;
			while (mascara) {
				g |= (bit_b >> 1) ^ (b & mascara);
				bit_b = b & mascara;
				mascara >>= 1;
			}
			if (fputc(g, out) == EOF) {
				puts(">>> Erro ao escrever no arquivo de saida! <<<");
				return -1;
			}
		}
	}
	return 0;
}

int gray2bin(FILE* in, FILE* out) {
	while (!feof(in)) {
		char g = fgetc(in);
		if (g == EOF) {
			if (ferror(in)) {
				puts(">>> Erro ao ler o arquivo de entrada! <<<");
				return -1;
			}
		}
		else {
			char b, bit_b, mascara;
			b = bit_b = g & MSB;
			mascara = MSB >> 1;
			while (mascara) {
				b |= (bit_b >> 1) ^ (g & mascara);
				bit_b = b & mascara;
				mascara >>= 1;
			}
			if (fputc(b, out) == EOF) {
				puts(">>> Erro ao escrever no arquivo de saida! <<<");
				return -1;
			}
		}
	}
	return 0;
}
