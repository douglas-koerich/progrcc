#include <stdio.h>

#define TAM	10

int main() {
	FILE* arq = fopen("vetor.txt", "wt");
	if (arq == NULL) {
		perror("Nao pude criar o arquivo vetor.txt");
		return -1;
	}
	int vetor[TAM], i;
	for (i=0; i<TAM; ++i) {
		printf("Digite o %do. numero do vetor: ", i+1);
		scanf("%d", vetor+i);
	}

	/*
	printf("O vetor digitado eh: ");
	for (i=0; i<TAM; ++i) {
		printf("%d ", vetor[i]);
	}
	putchar('\n');
	*/
	for (i=0; i<TAM; ++i) {
		if (fprintf(arq, "%d ", vetor[i]) < 0) {
			perror("Nao pude escrever o vetor no arquivo");
			fclose(arq);
			return -1;
		}
	}
	if (fputc('\n', arq) == EOF) {
		perror("Nao pude escrever o fim do arquivo");
		fclose(arq);
		return -1;
	}
	fclose(arq);
	return 0;
}

