#include <stdlib.h>
#include <stdio.h>

int main(void) {
	char nome[100];
	printf("Digite o nome do arquivo de log: ");
	gets(nome);

	FILE* arq = fopen(nome, "wb");
	if (arq == NULL) {
		perror("Nao pude criar o arquivo:");
		return EXIT_FAILURE;
	}
	int num;
	do {
		printf("Digite um numero: ");
		scanf("%d", &num);
		if (num >= 0) {
			if (fwrite(&num, sizeof(int), 1, arq) < 1) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
		}
	} while (num >= 0);

	if (fclose(arq) == EOF) {
		perror("Nao pude fechar o arquivo:");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

