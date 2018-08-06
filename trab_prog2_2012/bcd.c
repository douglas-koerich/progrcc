#include "bcd.h"

int bin2bcd(FILE* in, FILE* out) {
	while (!feof(in)) {
		char b = fgetc(in);
		if (b == EOF) {
			if (ferror(in)) {
				puts(">>> Erro ao ler o arquivo de entrada! <<<");
				return -1;
			}
		}
		else {
			char bl, bh;
			bh = b / 100;
			b %= 100;
			bl = ((b / 10) << 4) | (b % 10);
			if (fputc(bh, out) == EOF || fputc(bl, out) == EOF) {
				puts(">>> Erro ao escrever no arquivo de saida! <<<");
				return -1;
			}
		}
	}
	return 0;
}

#define LOW	0xF

int bcd2bin(FILE* in, FILE* out) {
	while (!feof(in)) {
		char h = fgetc(in);
		if (h == EOF) {
			if (ferror(in)) {
				puts(">>> Erro ao ler o arquivo de entrada! <<<");
				return -1;
			}
		}
		else {
			char l = fgetc(in);
			unsigned char b, bh, bl;
			if (l == EOF) {
				puts(">>> Erro ao ler o arquivo de entrada! <<<");
				return -1;
			}
			bh = h, bl = l;
			b = bh * 100;
			b += bl & LOW;
			b += (bl >> 4) * 10;
			if (fputc(b, out) == EOF) {
				puts(">>> Erro ao escrever no arquivo de saida! <<<");
				return -1;
			}
		}
	}
	return 0;
}

