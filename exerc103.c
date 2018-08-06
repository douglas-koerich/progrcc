#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "exerc103.h"

int main(void) {
	int num;
	printf("Quantos habitantes na populacao? ");
	scanf("%d", &num);

	// struct habitante* populacao =
	// 			(struct habitante*) malloc(num * sizeof(struct habitante));
	pessoa* populacao = (pessoa*) malloc(num * sizeof(pessoa));
	if (populacao == NULL) {
		perror("Erro de alocacao dinamica:");
		return EXIT_FAILURE;
	}
	// Preenche o vetor (v. funcao)
	ler(populacao, num);

	// Calcula media dos salarios da populacao
	float m = media(populacao, num);
	printf("A media de salario eh R$ %.2f\n", m);

	// Maior e menor idade
	unsigned short menor, maior;
	minmax(populacao, num, &menor, &maior);
	printf("A maior idade eh %hu e a menor eh %hu\n", maior, menor);

	// Numero de mulheres com 3 filhos e salario menor que 500
	unsigned mulh = mulheres(populacao, num);
	printf("Ha %u mulheres com 3 filhos ganhando menos que $500\n", mulh);

	free(populacao);
	return EXIT_SUCCESS;
}

void ler(pessoa vetor[], size_t tamanho) {
	for (int i=0; i<tamanho; ++i) {
		printf("Habitante %d: Idade? ", i+1);
		scanf("%hu", &vetor[i].idade);
		do {
			printf("Sexo (M/F)? ");
			__fpurge(stdin);
			vetor[i].sexo = toupper(getchar());
		} while (vetor[i].sexo != 'M' && vetor[i].sexo != 'F');
		printf("Salario? ");
		scanf("%f", &vetor[i].salario);
		printf("Filhos? ");
		scanf("%hu", &vetor[i].filhos);
	}
}

float media(pessoa* vetor, size_t tamanho) {
	float m = 0.0;
	for (int i=0; i<tamanho; ++i) {
		m += (vetor+i)->salario;
	}
	return m/tamanho;
}

void minmax(pessoa* v, size_t tam, unsigned short* m, unsigned short* M) {
	// Conteudo das variaveis (lah no main) apontadas pelos ponteiros sao inicializadas com a idade do primeiro registro
	*m = *M = v->idade;
	for (int i=0; i<tam; ++i, ++v) {
		if (v->idade < *m) {
			*m = v->idade;
		}
		if (v->idade > *M) {
			*M = v->idade;
		}
	}
}

unsigned mulheres(pessoa vetor[], size_t tamanho) {
	unsigned contador = 0;
	for (int i=0; i<tamanho; ++i) {
		unsigned short filhos = vetor[i].filhos;
		float salario = (*(vetor+i)).salario;
		if (filhos == 3 && salario < 500.0) {
			++contador;
		}
	}
	return contador;
}

