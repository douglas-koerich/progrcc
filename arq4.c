#include <stdio.h>

int main(void) {
	int num;
	printf("Digite um numero: ");
	scanf("%d", &num);

	// Primeira opcao: gravar o numero num arquivo-texto; isso implica
	// converter o numero para a string correspondente
	FILE* arq = fopen("num.txt", "wt");
	if (arq == NULL) {
		perror("Nao pude criar o arquivo-texto");
		return -1;
	}
	fprintf(arq, "%d\n", num);
	fclose(arq);

	// Segunda opcao: gravar o numero no formato original BINARIO
	arq = fopen("num.bin", "wb");	// b = arquivo/stream do tipo binario
	if (arq == NULL) {
		perror("Nao pude criar o arquivo-binario");
		return -1;
	}
	if (fwrite(&num, sizeof(int), 1, arq) < 1) { // nao escreveu o 1 int?
		perror("Nao pude escrever no arquivo-binario");
		return -1;
	}
	fclose(arq);
	return 0;
}


