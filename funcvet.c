#include <stdlib.h>		// srand() e rand()
#include <stdio.h>		// E/S do console
#include <time.h>		// time()

#define TAMANHO 15

float calculaMedia(int [*], size_t);

int main() {
	int vetor[TAMANHO], i;

	// Inicializa a semente de numeros aleatorios
	srand((unsigned)time(0));

	for (i=0; i<TAMANHO; ++i) {
		// Gera numeros aleatorios no intervalo 1-100
		vetor[i] = rand() % 100 + 1;
	}
	float m = calculaMedia(vetor, TAMANHO); 

	for (i=0; i<TAMANHO; ++i) {
		printf("%02d ", vetor[i]);
	}
	printf("\n");

	printf("A media dos valores eh %.3f.\n", m);

	return 0;
}

float calculaMedia(int v[], size_t tam) {
	/* Parametros equivalem a declarar como int v[tam]; */
	float media;
	int i;

	for (i=0, media=0.0; i<tam; ++i) {
		media += v[i];
	}
	media /= tam;
	return media;
}

