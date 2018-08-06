#include <stdio.h>
#include <stdlib.h>

void preenche(int*, int*);

int s; //= 1000;

void preenche(int* a, int* b) {
	int soma;
	printf("Digite a: "); scanf("%d", a);
	printf("Digite b: "); scanf("%d", b);
	soma = *a + *b;
	printf("Soma = %d\n", soma);
	s = -1;
}

int main() {
	int a, b, i;	// Essas variaveis sao diferentes de a e b de preenche()
	printf("s antes do preenche: %d\n", s);
	preenche(&a, &b);
	printf("s antes da soma: %d\n", s);
	for (i=a; i<=b; ++i) {
		int a;	// Esta variavel eh criada no inicio de *cada* repeticao
				// e destruida antes da proxima repeticao
		printf("a (antes) = %d, ", a);
		a = i;
		printf("a (depois) = %d, ", a);
	}
	s = a + b;
	printf("\ns depois da soma: %d\n", s);
	return 0;
}

