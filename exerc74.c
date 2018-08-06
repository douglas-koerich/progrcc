#include <stdio.h>

int main(void) {
	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	// Ja que o tamanho do vetor agora eh conhecido, vamos declara-lo
	// com o tamanho correto
	int vetor[n];	// isso soh eh valido para vetores como var. locais
					// assim, temos um vetor cujo tamanho varia de execucao
					// para execucao do programa, mas atencao! nao muda de
					// tamanho dentro da mesma execucao
	
	for (int j = 0; j < n; ++j) {
		printf("Digite o numero no indice %d: ", j);
		scanf("%d", &vetor[j]);
	}

	// Imprime o vetor original
	for (int j = 0; j < n; ++j) {
		printf("%d ", vetor[j]);
	}

	printf("\nDigite o numero de deslocamentos a esquerda: ");
	int m; scanf("%d", &m);

	// Deslocamento de uma posicao
	for (int j = 1; j <= m; ++j) {	// j eh o contador de vezes
		int i, aux = vetor[0];
		for (i = 0; i < n-1; ++i) {
			vetor[i] = vetor[i+1];	// copia da proxima para atual
		}
		vetor[n-1] = aux;
	}

	// Imprime o vetor deslocado
	for (int j = 0; j < n; ++j) {
		printf("%d ", vetor[j]);
	}
	return 0;
}



