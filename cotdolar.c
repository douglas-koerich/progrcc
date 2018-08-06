#include <stdio.h>

#define DIAS 7		// nao tem ponto-e-virgula!!!

// Prototipo da funcao que recebe um vetor como parametro
float calculaMedia(float [*], int);

int main() {
	// Vetor com valores iniciais
	float cotacoes[DIAS] = { 3.0, 2.9, 2.7, 5.6, 3.4, 2.8, 1.6 };
	// float cotacoes[] = { 3.0, 2.9, 2.7, 5.6, 3.4, 2.8, 1.6 };	// arriscado por fixar o tamanho
	// 																// em funcao da lista inicial
	int indice;
	int num_dias;

	/*
	// Nesta segunda versao, o usuario define quantos dias serao lidos
	do {
		printf("Digite o numero de dias para leitura: ");
		scanf("%d", &num_dias);
	} while (num_dias < 5 || num_dias > 15);
	*/

	// Vetor declarado com tamanho variavel
	// float cotacoes[num_dias];

	// Laco para preencher a lista de valores
	for (indice=0; indice<DIAS; ++indice) {
	// for (indice=0; indice<num_dias; ++indice) {
		printf("Digite a cotacao do %do. dia: ", indice+1);
		scanf("%f", &cotacoes[indice]);
	}

	// ... (outros processamentos) ...
	
	// Calculo da media e determinacao da maior e menor cotacao
	float maior, menor/*, media = 0.0*/;
	for (indice=0; indice<DIAS; ++indice) {
	// for (indice=0; indice<num_dias; ++indice) {
		// media += cotacoes[indice];	// acumulando em media cada valor
		if (indice == 0) {
			maior = menor = cotacoes[indice];
		}
		else {
			if (cotacoes[indice] > maior) {
				maior = cotacoes[indice];
			}
			if (cotacoes[indice] < menor) {
				menor = cotacoes[indice];
			}
		}
	}
	// media = media / DIAS;
	// media = media / num_dias;

	// ... (outros processamentos mais) ...

	// Imprime a lista de valores e os resultados
	for (indice=0; indice<DIAS; ++indice) {
	// for (indice=0; indice<num_dias; ++indice) {
		printf("R$ %.2f\n", cotacoes[indice]);
	}
	printf("Maior: R$ %.2f\n", maior);
	printf("Menor: R$ %.2f\n", menor);
	// printf("Media: R$ %.2f\n", media);
	printf("Media: R$ %.2f\n", calculaMedia(cotacoes, DIAS));

	return 0;
}

float calculaMedia(float vetor[], int tamanho) {
	float media = 0.0;
	int indice;
	for (indice=0; indice<DIAS; ++indice) {
		media += vetor[indice];	// acumulando em media cada valor
	}
	media = media / tamanho;
	return media;
}

