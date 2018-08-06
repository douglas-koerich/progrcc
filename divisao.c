#include <stdio.h>

// inicio
int main() {
	// declare a, b, c : inteiro
	int a, b, c;

	// leia a, b
	printf("Digite a: "); scanf("%d", &a);
	printf("Digite b: "); scanf("%d", &b);

	// se b <> 0 entao
	// if (b != 0) {
	if (b) {
	
		// c <- a/b
		c = a / b;
		
		// escreva c
		printf("c = %d\n", c);
	}
	// senao
	else {
		// escreva "Divisor ZERO!"
		printf("Divisor ZERO!\n");

	// fim-se
	} 
// fim
	return 0;
}

/* Teste de valor igual a zero
 * if (x == 0) { ...
 * ou
 * if (!x) { ...
 */
