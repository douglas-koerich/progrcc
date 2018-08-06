#include <stdio.h>

#define DIAS 15

int main() {
	// Um vetor para armazenar as temperaturas de cada dia
	float temp[DIAS];	// numero de elementos/posicoes/valores armazenados
	int dia;

	// Gravando valores aleatoriamente no vetor
	temp[0] = 12.5;	// primeira posicao do vetor
	temp[5] = 30.0;	// 6a. posicao do vetor
	temp[DIAS-1] = 35.1; // ultima posicao do vetor
	/*
	temp[40] = 34.0; // INVALIDA, mas o compilador ACEITA!!!
	temp[-10] = 0.0; // IDEM!
	*/

	// Para percorrer (preenchendo, imprimindo, lendo, etc.) os dados de um
	// vetor, usamos um LACO, onde a variavel de controle do laco eh tambem
	// o marcador de posicao dentro do vetor
	for (dia=1; dia<=DIAS; ++dia) {
		printf("Digite a temperatura do dia %d: ", dia);
		scanf("%f", &temp[dia-1]);	// porque o vetor nao comeca no indice [1]
	}
	/* O mais comum eh, no entanto, fazer como a seguir (usando 0 como primeiro valor)
	for (dia=0; dia<DIAS; ++dia) {	// lembrar de substituir <= por <
		printf("Digite a temperatura do dia %d: ", dia+1);
		scanf("%f", &temp[dia]);
	}
	*/

	printf("A temperatura medida no primeiro dia foi %.1f celsius.\n", temp[0]);
	printf("A temperatura medida no ultimo dia foi %.1f celsius.\n", temp[DIAS-1]);

	return 0;
}

