#include <stdio.h>
#include <math.h>
// inicio
int main() {
	// declare inicial, valor, desejado, juro: real
	float inicial, valor, desejado, juro;	
	// declare meses: inteiro
	int meses = 0;	
	// leia inicial, esperado, juro
	printf("Digite o capital inicial: ");
	scanf("%f", &inicial);
	printf("Digite o capital esperado: ");
	scanf("%f", &desejado);
	printf("Digite a taxa de juros (%%): ");
	scanf("%f", &juro);
	juro /= 100.0;	// percentagem -> absoluto	
	// valor <- inicial
	valor = inicial;	
	// meses <- 0
	meses = 0;	
	// enquanto valor < desejado faça
	while (valor < desejado) {	
		// meses <- meses + 1
		// ++meses;		// veja linha abaixo...
		// valor <- valor * (1+juro)**meses
		valor *= pow(1+juro, ++meses); // inc. antes de usar!		
	// fim-enquanto
	}
	// escreva "Vou viajar com " valor " depois de " meses
	printf("Vou viajar com %.2f depois de %d meses\n", valor, meses);
	return 0;
// fim
}

