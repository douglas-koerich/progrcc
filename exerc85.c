#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int num;
	printf("Quantas notas serao digitadas? ");
	scanf("%d", &num);

	/*
	// Declaracao (alocacao ESTATICA) de um vetor (variavel
	// local) com 'num' elementos/notas
	float notas[num];
	*/
	// num*sizeof(float) ==> numero de bytes para alocar
	// (float*) ==> cast pra dizer que o endereco retornado
	// 				pelo malloc eh para um conteudo-float
	float *notas = (float*) malloc(num*sizeof(float));
	if (notas == NULL) {
		puts("Erro de alocacao dinamica.");
		return EXIT_FAILURE;
	}
	float media = 0.0;	// vai somar e depois dividir por 'num'
	int i;

	// Leitura das notas
	for (i=0; i<num; ++i) {
		printf("Digite a nota do elemento %d: ", i);
		scanf("%f", notas+i);	// scanf("%f", &notas[i]);

		// Aproveita para acumular soma em 'media'
		media += *(notas+i);	// media += notas[i];
	}
	// Calcula media
	media /= num;

	int contador_abaixo = 0, contador_acima = 0;

	// Percorre o vetor avaliando cada nota, comparando com a
	// media (desvio de 10%)
	for (i=0; i<num; ++i) {
		if (notas[i] < media*0.9) {
			++contador_abaixo;
		}
		if (notas[i] > media*1.1) {
			++contador_acima;
		}
	}
	// RESPONSABILIDADE DO PROGRAMADOR: destruir (liberar) a
	// reserva de memoria feita pelo malloc
	free(notas);	// tem que passar o mesmo endereco que o
					// malloc me deu, e que salvei (e NAO
					// PERDI!!!) no ponteiro 'notas'
					// Eh proibido fazer ++notas, --notas, etc

	printf("Ha %d notas abaixo de 10%% da media (%.1f) e %d notas acima.\n", contador_abaixo, media, contador_acima);

	return EXIT_SUCCESS;
}

