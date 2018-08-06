#include <stdio.h>

int main(int argc, char* argv[]) {
	int checksum = 0;
	FILE* fin, * fout;
	if (argc != 3) {
		puts("Numero invalido de parametros");
		printf("Uso: %s <arq-entrada> <arq-checksum>\n", argv[0]);
		puts("Onde - <arq-entrada> eh o nome do arquivo do qual se vai calcular o checksum");
		puts("       <arq-checksum> eh o nome do arquivo que vai armazenar o checksum calculado");
		return -1;
	}
	fin = fopen(argv[1], "rb");
	if (fin == NULL) {
		perror("Nao pode abrir o arquivo de entrada");
		return -1;
	}
	while (!feof(fin)) {
		char byte = fgetc(fin);
		if (byte == EOF) {
			if (ferror(fin)) {
				perror("Nao pode ler o conteudo do arquivo de entrada");
				fclose(fin);
				return -1;
			}
		}
		else {
			checksum += byte;
		}
	}
	fclose(fin);

	fout = fopen(argv[2], "wb");
	if (fout == NULL) {
		perror("Nao pode criar o arquivo de checksum");
		return -1;
	}
	fwrite(&checksum, sizeof(int), 1, fout);
	fclose(fout);
	return 0;
}

