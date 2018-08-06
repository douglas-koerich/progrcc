#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX	20

int main() {
	// Inicializa semente do gerador de numeros randomicos (aleatorios)
	srand((unsigned) time(0));

	// O vetor de entrada
	int vetor[MAX], i;

	// Preenchendo o vetor com numeros aleatorios de 1 a 20
	for (i=0; i<MAX; ++i) {
		vetor[i] = rand() % 20 + 1;
	}
	// Imprime o vetor
	printf("Vetor de entrada: ");
	for (i=0; i<MAX; ++i) {
		printf("%d ", vetor[i]);
	}
	printf("\n");

	// Vetor contendo os valores SEM repeti-los
	int saida[MAX];

	// Vetor com a contagem de cada elemento contido no vetor de saida
	unsigned contagem[MAX] = { 0 };	// todas as posicoes ficam inicializadas com zero

	// Como o vetor de saida (e o de contagem que vai crescer junto com ele) pode
	// ter menos elementos que o vetor de entrada (no vetor de saida estao todos os
	// elementos SEM suas ocorrencias repetidas) temos que ter um indice que controla
	// onde esta o fim desse vetor
	int s = 0;

	// Percorre o vetor de entrada
	for (i=0; i<MAX; ++i) {
		// Procura o elemento i do vetor de entrada no vetor de saida
		int j;
		for (j=0; j<s; ++j) {
			// Se encontrou o elemento no vetor de saida, eh porque este valor
			// ja foi encontrado numa posicao anterior de i
			if (vetor[i] == saida[j]) {
				// Incrementa o contador desse elemento que estah em saida[j] (mais uma
				// repeticao)
				++contagem[j];	// note que o indice eh j
				break;			// INTERROMPE o laco *interno* (ao qual pertence diretamente)
			}
		}
		// Se chegou ao fim dos elementos jah inseridos no vetor de saida...
		if (j == s) {
			// ... eh porque o elemento em vetor[i] nao tinha sido encontrado antes,
			// poe o mesmo no vetor de saida, conta-o e aumenta o tamanho do vetor de saida
			// em mais um
			contagem[j] = 1;
			saida[s++] = vetor[i];	// Note que o limite 's' do vetor de saida eh incrementado
									// APOS a copia do valor
		}
	}
	// Imprime o vetor de saida com as contagens correspondentes
	printf("Vetor de saida (com contador): ");
	for (i=0; i<s; ++i) {
		printf("%d(%u) ", saida[i], contagem[i]);
	}
	printf("\n");

	return 0;
}

