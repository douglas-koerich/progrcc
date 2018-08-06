#include <stdio.h>
#include <stdlib.h>

int main() {
	// int a, b;
	int* a = (int*) malloc(sizeof(int));	// Numero de BYTES, nao de variaveis/elementos!
	int* b = (int*) malloc(sizeof(int));

	printf("Digite a: ");
	scanf("%d", a);

	printf("Digite b: ");
	scanf("%d", b);

	// int c;
	int* c = (int*) malloc(sizeof(int));
   	*c = *a + *b;

	// float d = c / 2.0;
	float* d = (float*) malloc(sizeof(float));
	*d = *c / 2.0;

	printf("A soma dos numeros eh %d e a metade da soma eh %f.\n", *c, *d);

	free(a);	// Eh ESSENCIAL nao perder o valor desses ponteiros!
	free(b);
	free(c);
	free(d);

	return 0;
}

