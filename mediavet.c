#include <stdlib.h>
#include <stdio.h>

//float calcMedia(int v[*], int tam);
float calcMedia(int* v, int tam);

int main() {
	int i, tamanho;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanho);

	// Vetor de tamanho variavel

	/* Este codigo soh funciona para compiladores C mais modernos
	int vetor[tamanho];
	*/

	// Quando o compilador nao suporta a declaracao (alocacao estatica) de
	// um vetor com tamanho variavel, a saida eh usar alocacao dinamica
	int* vetor = (int*) malloc(tamanho * sizeof(int));	// passa o tamanho EM BYTES
//	 ^             ^
//	 |             |
//	 +---IGUAIS----+

	for (i=0; i<tamanho; ++i) {
		printf("Digite o valor de vetor[%d]: ", i);
		//scanf("%d", &vetor[i]);
		scanf("%d", vetor+i);	// v+i <=> &v[i]
	}
	float media = calcMedia(vetor, tamanho);
	printf("A media eh %f\n", media);

	// Agora, depois de usar a pseudo-variavel 'vetor' alocada dinamicamente,
	// devo LIBERAR essa memoria do contrario ela ficara "presa" quando o programa
	// terminar (porque o S.O. ainda tem esse bloco como vinculado ao meu programa)
	free(vetor);	// ***###*** DEVE SER O MESMO ENDERECO RETORNADO POR malloc()

	return 0;
}

//float calcMedia(int v[], int tam) {
float calcMedia(int* v, int tam) {
	int i;
	float m = 0.0;
	for (i=0; i<tam; ++i) {
		//m += v[i];
		m += *(v+i);	// *(v+i) <=> v[i]
	}
	m = m / tam;
	return m;
}
