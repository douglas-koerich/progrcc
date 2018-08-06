#include <libgen.h>
#ifdef WIN32
#include <string.h>
#else
#include <strings.h>
#endif
#include "bcd.h"
#include "gray.h"

void ajuda(const char* nomeprog) {
	printf("\nUSO: %s <operacao> <arq-entrada> <arq-saida>\n", nomeprog);
	puts("operacao: conversao a ser efetuada sobre 'arq-entrada'");
	puts("\t-B    binario para BCD");
	puts("\t-G    binario para Gray");
	puts("\t-b    BCD para binario");
	puts("\t-g    Gray para binario");
	puts("arq-entrada: nome do arquivo a ser convertido");
	puts("arq-saida: nome do arquivo resultante da conversao");
}

int main(int argc, char* argv[]) {
	FILE *entrada, *saida;
	int res;
	if (argc != 4) {
		puts(">>> Numero invalido de parametros! <<<");
		ajuda(basename(argv[0]));
		return -1;
	}
#ifdef WIN32
	if (stricmp(argv[1], "-b" && stricmp(argv[1], "-g")) {
#else
	if (strcasecmp(argv[1], "-b") && strcasecmp(argv[1], "-g")) {
#endif
		puts(">>> Operacao invalida! <<<");
		ajuda(basename(argv[0]));
		return -1;
	}
	entrada = fopen(argv[2], "rb");
	if (entrada == NULL) {
		printf(">>> Nao pode abrir arquivo '%s'! <<<", argv[2]);
		return -1;
	}
	saida = fopen(argv[3], "wb");
	if (saida == NULL) {
		fclose(entrada);

		printf(">>> Nao pode criar arquivo '%s'! <<<", argv[3]);
		return -1;
	}
	switch (argv[1][1]) {
		case 'B':
			res = bin2bcd(entrada, saida);
			break;

		case 'b':
			res = bcd2bin(entrada, saida);
			break;

		case 'G':
			res = bin2gray(entrada, saida);
			break;

		case 'g':
			res = gray2bin(entrada, saida);
	}
	fclose(entrada);
	fclose(saida);
	return 0;
}

