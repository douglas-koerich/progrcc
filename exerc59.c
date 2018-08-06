#include <stdio.h>

int main(void) {
	int num, absoluto;

	printf("Digite um numero qualquer: ");
	scanf("%d", &num);

	// Chamada da funcao
	absoluto = calculaAbsoluto(num);

	printf("O valor absoluto eh %d.\n", absoluto);
	// printf("O valor absoluto eh %d.\n", calculaAbsoluto(num));

	return 0;
}

// Definicao da funcao
int calculaAbsoluto(int numero) {
	int absoluto;	// outra variavel, diferente daquela da funcao main()

	if (numero < 0) {
		absoluto = -numero;
	}
	else {
		absoluto = numero;
	}
	// absoluto = numero < 0? -numero: numero;
	
	return absoluto;
}

