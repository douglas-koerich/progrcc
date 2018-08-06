#include <stdio.h> 

#define NUM	10

int main() {
	int num;

	printf("Numero de elementos da sequencia? ");
	scanf("%d", &num);

	// int sequencia[NUM];
	int sequencia[num];
	int indice;

	// for (indice=0; indice<NUM; ++indice) {
	for (indice=0; indice<num; ++indice) {
		printf("sequencia[%d]? ", indice);
		scanf("%d", &sequencia[indice]);
	}

	// for (indice=NUM-1; indice>=0; --indice) {
	for (indice=num-1; indice>=0; --indice) {
		printf("sequencia[%d]: %d\n", indice, sequencia[indice]);
	}
	return 0;
}

