#include <stdio.h>

// inicio
int main() {
	// declare n, mul : inteiro
	int n, mul;
	// declare fat : real	; pode ultrapassar a capacidade de um inteiro
	float fat;
	// leia n
	printf("Digite o numero: ");
	scanf("%d", &n);
	// fat <- 1.0
	// fat = 1.0;	---> deixo para a inicializacao do laco for...
	// para mul de 1 ate n passo 1 faca
	for (mul=1, fat=1.0; mul<=n; ++mul) {
		// fat <- fat * mul
		fat *= mul;	// fat = fat * mul;
		printf("Estou no passo %d com valor atual de fat em %f...\n", mul, fat);
	// fim-para
	}
	// escreva fat
	printf("Fatorial do numero eh %f\n", fat); 
	return 0;
// fim
}

