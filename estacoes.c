#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void imprime(float [*], int);

#define	NUM_DIAS	10	// antes era 90

int main(void) {
	// Declaracao de um vetor:
	// <tipo_unico> <nome_comum_variavel>[<num_de_elementos>];
	// float verao[90];		// definir com numero fixo "amarra" o codigo
	float verao[NUM_DIAS];	// vetor com 90 posicoes/elementos/floats
	float outono[NUM_DIAS], inverno[NUM_DIAS], primavera[NUM_DIAS];
	int indice, indice2, dia;

	// Inicializa o gerador de numeros aleatorios
	srand((unsigned) time(0));

	// Preenche as temperaturas do verao
	// verao[0] = ...
	// ...
	// verao[89] = ...
	// Ao inves, deve usar um laco para preencher o vetor
	for (indice = 0; indice < NUM_DIAS; ++indice) {
		printf("Digite a temperatura do dia %d: ", indice);
		scanf("%f", &verao[indice]);
	}
	// Para conferir, vamos ver se o vetor tem os valores digitados
	printf("### LISTAGEM DE TEMPERATURAS DO VERAO ###\n");
	for (indice = 0; indice < NUM_DIAS; ++indice) {
		printf("Temperatura do dia %d: %.1f\n", indice, verao[indice]);
	}
	// Imprime a temperatura do 10o. dia
	printf("Temperatura do decimo dia: %.1f\n", verao[9]);
	// Consulta um dia qualquer
	do {
		printf("Digite um dia para pesquisa (1-%d): ", NUM_DIAS);
		scanf("%d", &dia);
	} while (dia < 1 || dia > NUM_DIAS);
	printf("Temperatura no dia %d do verao: %.1f\n", dia, verao[dia-1]);

	// Coincidencia de Sao Pedro: as temperaturas do outono foram iguais
	// as do verao
	// outono = verao;		// nao eh possivel copiar vetor como nesta linha
	for (indice = 0; indice < NUM_DIAS; ++indice) {
		outono[indice] = verao[indice];
	}
	// Ja a primavera teve os valores exatamente na ordem inversa do verao
	for (indice = 0, indice2 = NUM_DIAS-1; indice < NUM_DIAS;
		 ++indice, --indice2) {
		primavera[indice2] = verao[indice];
	}
	// Gera as temperaturas do inverno na faixa de 0 a 15.9 graus
	for (indice = 0; indice < NUM_DIAS; ++indice) {
		// rand() gera numeros INTEIROS de 0 a 4 bilhoes e "pouco"...
		// para ter numeros INTEIROS de 0 a 159 pego o aleatorio e divido
		// por 160, ou melhor, pego o resto da divisao (mod) por 160
		// em seguida, divido o INTEIRO por 10 para ter um REAL com 1 casa
		// decimal
		inverno[indice] = (rand() % 160) / 10.0;
	}
	// Ao inves de repetir 3 vezes o laco que imprime cada vetor (um para
	// outono, outro para inverno e mais um para primavera, vou chamar uma
	// funcao que RECEBE UM VETOR COMO PARAMETRO e faz a impressao
	printf("### LISTAGEM DE TEMPERATURAS DO OUTONO ###\n");
	imprime(outono /* soh o nome, sem colchetes */, NUM_DIAS);
	printf("### LISTAGEM DE TEMPERATURAS DO INVERNO ###\n");
	imprime(inverno, NUM_DIAS);
	printf("### LISTAGEM DE TEMPERATURAS DA PRIMAVERA ###\n");
	imprime(primavera, NUM_DIAS);

	return EXIT_SUCCESS;	// 0
}

/*
void imprime(int num, float estacao[num]) { // pouco usado, exige mudar a
											// ordem la embaixo
*/
void imprime(float estacao[],	// vetor como parametro tem tamanho variavel
			 int num)			// entao precisa passar o tamanho tambem
{
	int indice;
	for (indice = 0; indice < num; ++indice) {
		printf("Temperatura do dia %d: %.1f\n", indice, estacao[indice]);
	}
}
