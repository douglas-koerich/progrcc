#include <stdio.h>
#include <stdlib.h>

int main(void) {
	size_t tamanho;

	printf("Quantos numeros? ");
	scanf("%u", &tamanho);
	
	// Sem o padrao C99, ou se o tamanho eh muito grande para caber na
	// pilha, soh nos resta fazer alocacao dinamica dos vetores
	int* vetor = (int*) malloc(sizeof(int)*tamanho);	// num de BYTES!!!
	int* multiplos = (int*) malloc(sizeof(int)*tamanho);

	int i;
	for (i=0; i<tamanho; ++i) {
		printf("Numero na posicao %d? ", i);
		scanf("%d", vetor+i);	// &vetor[i] <=> vetor+i

		/*
		if (i % 2)	{	// par cardinal, impar ordinal (lembrar: 0=falso)
			multiplos[i] = 2 * vetor[i];
		}
		else {
			multiplos[i] = 3 * vetor[i];
		}
		*/
		multiplos[i] = (i % 2? 2: 3) * vetor[i];
	}
	for (i=0; i<tamanho; ++i) {
		printf("%d ", vetor[i]);
	}
	putchar('\n');
	for (i=0; i<tamanho; ++i) {
		printf("%d ", multiplos[i]);
	}
	putchar('\n');

	// Agora nao pode esquecer de liberar a memoria ("memory leak")
	free(multiplos);
	free(vetor);

	return 0;
}

