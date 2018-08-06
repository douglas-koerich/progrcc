#include <stdlib.h>
#include <stdio.h>

int main() {
	unsigned n;
	printf("Digite o numero de notas: ");
	scanf("%u", &n);

	// float vetor[n];
	float* vetor = (float*) malloc(n * sizeof(float)), media = 0.0;
	int i;
	for (i=0; i<n; ++i) {
		printf("Nota do aluno #%d: ", i+1);
		scanf("%f", vetor+i);	// scanf("%f", &vetor[i]);

		// Ao inves de fazer isso num proximo laco, aproveito e jah
		// calculo a media (ou melhor, a soma) aqui mesmo
		media += *(vetor+i);
	}
	media /= n;	// calculo da media

	unsigned maiores = 0, menores = 0;
	for (i=0; i<n; ++i) {
		if (vetor[i] <= media * 0.9) {
			++menores;
		}
		else if (*(vetor+i) >= media * 1.1) {
			++maiores;
		}
	}
	// Como nao preciso mais do vetor, ja libero a memoria aqui
	free(vetor);

	printf("A media eh %.2f.\n", media);
	printf("Numero de notas menores que 90%% da media: %u.\n", menores);
	printf("Numero de notas maiores que 110%% da media: %u.\n", maiores);

	return 0;
}

