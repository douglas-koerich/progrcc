#include <stdio.h>

// Como nao eh possivel "retornar um vetor", passa-se o vetor a
// ser preenchido como parametro, pra que a funcao altere o seu
// conteudo
void fatorialVetor(unsigned [*], unsigned [*], size_t);

#define TAM	10

int main(void) {
	unsigned vetor_1[TAM], vetor_2[TAM], indice;

	for (indice = 0; indice < TAM; ++indice) {
		printf("Digite valor no indice %u: ", indice);
		scanf("%u", &vetor_1[indice]);
	}
	printf("Vetor 1: ");
	for (indice = 0; indice < TAM; ++indice) {
		printf("%u ", vetor_1[indice]);
	}
	fatorialVetor(vetor_1, vetor_2, TAM);
	printf("\nVetor 2: ");
	for (indice = 0; indice < TAM; ++indice) {
		printf("%u ", vetor_2[indice]);
	}
	printf("\n");
	return 0;
}

void fatorialVetor(unsigned v1[], unsigned v2[], size_t tam) {
	unsigned indice;
	for (indice = 0; indice < tam; ++indice) {
		unsigned parc;
		for (v2[indice] = 1, parc = v1[indice]; parc > 0; --parc) {
			v2[indice] *= parc;
		}
	}
}

