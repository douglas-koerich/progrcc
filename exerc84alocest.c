#include <stdio.h>

// Alocacao estatica obriga definir o tamanho durante a compilacao
#define	TAMANHO	10

int main() {
	int primeiro[TAMANHO], segundo[TAMANHO];	// alocacao estatica!
	unsigned tamanho;

	// Com alocacao estatica preciso verificar se nao estoura a previsao
	// de espaco feita em tempo de compilacao
	do {
		printf("Tamanho do vetor (max. %d): ", TAMANHO);
		scanf("%u", &tamanho);
	} while (tamanho > TAMANHO);

	int i;
	for (i=0; i<tamanho; ++i) {
		printf("Elemento %d: ", i);
		scanf("%d", &primeiro[i]);
	}
	printf("Vetor de entrada: ");
	for (i=0; i<tamanho; ++i) {
		printf("%d ", primeiro[i]);
	}
	putchar('\n');

	// Vamos gerar o segundo vetor em funcao do primeiro
	for (i=0; i<tamanho; ++i) {
		// Posicao ordinal par (segundo, quarto, sexto) equivale a indice
		// cardinal impar (indice 1, indice 3, indice 5)
		if (i % 2 != 0) {
			segundo[i] = 2 * primeiro[i];
		}
		else {
			segundo[i] = 3 * primeiro[i];
		}
	}
	printf("Vetor de saida: ");
	for (i=0; i<tamanho; ++i) {
		printf("%d ", segundo[i]);
	}
	putchar('\n');

	return 0;
}

