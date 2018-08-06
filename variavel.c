#include <stdio.h>	// scanf() e printf()

// inicio
int main() {
//		declare r: inteiro
	int r;
// 		leia r
	printf("Digite o valor do raio: ");
	scanf("%d", &r);

// 		declare C, A: real
	float C, A;	/* Esta declaracao no meio do bloco de codigo soh eh
				   suportada por compiladores mais modernos (nao VC++) */

// 		C <- 2 * 3.1416 * r
	C = 2 * 3.1416 * r;
// 		A <- 3.1416 * r ^ 2
	A = 3.1416 * r * r;
// 		escreva C, A
	printf("Comprimento=%f, Area=%f\n", C, A);
// fim
	return 0;
}
