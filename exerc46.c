#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int numero, num, n, primo, contador;
	bool ehPrimo;

	// Le o numero
	printf("Digite um numero: ");
	scanf("%d", &numero);

	// Para todos os numeros entre 1 e o numero digitado, EXCLUSIVE...
	printf("%d = ", numero);
	for (num = numero-1; num > 1; --num) {
		// Testa se o numero eh primo; pra isso, verifica se o unico
		// divisor do numero abaixo de si mesmo eh 1
		ehPrimo = true;		// comeca supondo que o numero eh primo, sim
		for (n = num-1; n > 1 && ehPrimo == true; --n) {
			if (num % n == 0) {	// existe um divisor n intermediario
				ehPrimo = false;// vai interromper o laco (ehPrimo != true)
			}
		}
		if (ehPrimo) {
			primo = num;
		}
		else {
			// Testa proximo numero (abaixo)
			continue;	// volta pro inicio do laco, pra novo valor
		}
		// Verifica se este primo eh divisor/fator do numero digitado
		contador = 0;
		while (numero % primo == 0) {
			numero /= primo;
			++contador;
		}
		if (contador > 0) {
			printf("%d(%d) ", primo, contador);
		}
	}
	printf("\n");
	return 0;
}

