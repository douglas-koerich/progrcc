#include <stdio.h>

void imprimeFibonacci(unsigned, unsigned);

int main() {
	unsigned referencia, N;

	printf("Qual o numero de referencia? ");
	scanf("%u", &referencia);

	printf("Quantos numeros vai imprimir? ");
	scanf("%u", &N);\

	imprimeFibonacci(referencia, N);

	return 0;
}

void imprimeFibonacci(unsigned ref, unsigned n) {
	unsigned fib_ant_anterior = 0,
			 fib_anterior = 1,
			 fib_calcular,
			 contador = 0;

	if (n == 0) {
		return;		// nao ha nada a imprimir, pra que calcular?
	}

	while (contador < n) {
		fib_calcular = fib_anterior + fib_ant_anterior;
		if (fib_calcular > ref) {	// v. enunciado
			printf("%u ", fib_calcular);
			++contador;	// soh conta quando imprime (v. enunciado)
		}
		fib_ant_anterior = fib_anterior;
		fib_anterior = fib_calcular;
	}
	printf("\n");
}
