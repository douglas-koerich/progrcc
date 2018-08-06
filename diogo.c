#include <stdio.h>
#include "samuel.h"

int main(void) {
	unsigned N;

	printf("Digite o valor de N: ");
	scanf("%u", &N);

	float S;
	S = somatorio(N);

	printf("A soma da expressao resultou %.4f\n", S);

	return 0;
}

