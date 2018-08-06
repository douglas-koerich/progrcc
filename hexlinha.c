#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		puts("Numero invalido de parametros!");
		printf("Use: %s <nome-arq-entrada> <nome-arq-saida>\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE* arqin = fopen(argv[1], "r");
	if (arqin == NULL) {
		perror("Nao pude abrir o arquivo:");
		return EXIT_FAILURE;
	}
	FILE* arqout = fopen(argv[2], "w");
	if (arqout == NULL) {
		perror("Nao pude criar o arquivo:");
		return EXIT_FAILURE;
	}
	while (!feof(arqin)) {
		const int MAX_LINHA = 2000;
		char linha[MAX_LINHA];
		if (fgets(linha, sizeof(linha), arqin) == NULL) {
			if (ferror(arqin)) {
				perror("Nao pude ler o arquivo:");
				return EXIT_FAILURE;
			}
		}
		else {
			// Remove o '\n' do fim da string lida do arquivo
			char* posCR = strrchr(linha, '\n');
			*posCR = '\0';
			// Podia fazer tambem assim:
			// linha[strlen(linha)-1] = '\0';

			// Poe no arquivo de saida a linha original (sem o \n)
			if (fprintf(arqout, "%s = ", linha) < 0) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
			// Agora, para cada caracter na string/linha original
			char* caracter = linha;	// aponta para inicio do vetor/string
			while (*caracter != '\0') {
				if (fprintf(arqout, "%02x ", *caracter) < 0) {
					perror("Nao pude escrever no arquivo:");
					return EXIT_FAILURE;
				}
				++caracter;
			}
			// Termina a linha com um salto de linha (que nao veio da original)
			if (fputc('\n', arqout) == EOF) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
		}
	}

	if (fclose(arqin) == EOF || fclose(arqout) == EOF) {
		perror("Nao pude fechar o arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

