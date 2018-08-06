#include <stdio.h>

int main(void) {
	char string[200];
	printf("Digite uma frase: ");
	gets(string);

	FILE* fp = fopen("crypto.txt", "wt");
	if (fp == NULL) {
		perror("Nao pude criar o arquivo");
		return -1;
	}
	/* 1a. solucao: criptografar na propria string e escreve-la no arquivo 
	int i=0;
	while (string[i] != '\0') {
		++string[i++];	// incrementa o codigo ASCII do simbolo original
	}
	if (fputs(string, fp) == EOF) {
		perror("Nao pude escrever no arquivo");
		return -1;
	}
	*/
	// 2a. solucao: escrever o criptografado de cada caracter
	int i=0;
	while (string[i] != '\0') {
		if (fputc(string[i++]+1, fp) == EOF) {
			perror("Nao pude escrever no arquivo");
			return -1;
		}
	}
	fclose(fp);
	return 0;
}

