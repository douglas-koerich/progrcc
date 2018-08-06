#include <stdio.h>

int main(void) {
	size_t tamanho;

	printf("Quantos numeros? ");
	scanf("%u", &tamanho);
	
	// Isto soh funciona a partir do padrao C99
	int vetor[tamanho];	// vetor de tamanho definido por variavel
	int multiplos[tamanho];

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

	return 0;
}

