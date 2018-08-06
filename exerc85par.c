#include <stdlib.h>
#include <stdio.h>

int main(int numparam, char* listaparam[]) {
	/*
	int num;
	printf("Quantas notas serao digitadas? ");
	scanf("%d", &num);
	*/
	if (numparam == 1) {
		puts("Numero invalido de parametros!");
		printf("Comando: %s <lista de notas>\n", listaparam[0]);
		return EXIT_FAILURE;
	}
	int num = numparam-1;	// numparam conta tambem o nome do
							// programa na linha de comando
	float notas[num];

	float media = 0.0;	// vai somar e depois dividir por 'num'
	int i;

	// Conversao das notas de strings (parametros sao SEMPRE
	// strings!) para float's
	for (i=0; i<num; ++i) {
		/*
		printf("Digite a nota do elemento %d: ", i);
		scanf("%f", notas+i);	// scanf("%f", &notas[i]);
		*/

		// Lembrar que tem que pular o listaparam[0], porque
		// ele tem o NOME do programa, e nao uma das notas
		notas[i] = atof(listaparam[i+1]);

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

	printf("Ha %d notas abaixo de 10%% da media (%.1f) e %d notas acima.\n", contador_abaixo, media, contador_acima);

	return EXIT_SUCCESS;
}

