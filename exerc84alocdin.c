#include <stdlib.h>
#include <stdio.h>

int main() {
	unsigned tamanho;

	// Com alocacao dinamica sou livre para definir o tamanho que quiser
	printf("Tamanho do vetor: ");
	scanf("%u", &tamanho);

	// Chama o sistema operacional para me fornecer uma area de memoria da
	// HEAP com numero de BYTES suficientes para o vetor de 'tamanho' ints
	int bytes = tamanho*sizeof(int);
	int* primeiro = (int*) malloc(bytes);	// o sistema operacional reserva
											// em BYTES (nao conhece int!)
	if (primeiro == NULL) {	// sistema operacional nao achou memoria LIVRE!
		puts("Estouro de memoria!");
		return -1;
	}

	int* segundo = (int*) malloc(tamanho*sizeof(int));
	
	int i;
	for (i=0; i<tamanho; ++i) {
		printf("Elemento %d: ", i);
		scanf("%d", primeiro+i);
	}
	printf("Vetor de entrada: ");
	for (i=0; i<tamanho; ++i) {
		printf("%d ", *(primeiro+i));
	}
	putchar('\n');

	// Vamos gerar o segundo vetor em funcao do primeiro
	for (i=0; i<tamanho; ++i) {
		// Posicao ordinal par (segundo, quarto, sexto) equivale a indice
		// cardinal impar (indice 1, indice 3, indice 5)
		*(segundo+i) = *(primeiro+i) * (i%2 != 0? 2: 3);
	}
	printf("Vetor de saida: ");
	for (i=0; i<tamanho; ++i) {
		printf("%d ", segundo[i]);
	}
	/* ESTE CODIGO GERA CRASH DA APLICACAO!!! (pq perde o endereco dado
	 * pelo malloc)
	for (i=0; i<tamanho; ++i, ++segundo) {
		printf("%d ", *segundo);
	}
	*/
	putchar('\n');
	
	// Alocacao dinamica requer que o programador faca o gerenciamento da
	// memoria, devolvendo ao sistema a memoria que nao eh mais usada
	free(primeiro);
	free(segundo);

	return 0;
}

