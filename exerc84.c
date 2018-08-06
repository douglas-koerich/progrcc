#include <stdio.h>

void func(int*, int*, int);	// antes faziamos: void func(int [*], int [*], int)

int main(void) {
	int num;
	printf("Quantos elementos tem o vetor? ");
	scanf("%d", &num);

	int v_entrada[num];
	for (int i=0; i<num; ++i) {
		printf("Digite o valor do %do. elemento: ", i+1);
		scanf("%d", v_entrada+i);	// ao inves de &v_entrada[i]
	}

	int v_saida[num];
	func(v_entrada, v_saida, num);

	for (int i=0; i<num; ++i) {
		printf("%d ", *(v_saida+i));	// ao inves de v_saida[i]
	}
	putchar('\n');

	return 0;
}

void func(int* in, int* out, int t) {
	// Posicoes ordinais impares (1a., 3a., 5a., ...)
	for (int i=0; i<t; i+=2) {
		*(out+i) = *(in+i) * 3;	// out[i] = in[i] * 3;
	}
	// Usando ponteiros que caminham nas posicoes pares dos vetores...
	int *pin = in+1, *pout = out+1;
	for (int i=1; i<t; i+=2, pin+=2, pout+=2) {
		*pout = *pin * 2;	// ponteiros pXXX (auxiliares) nao estao fixos!
	}
}

