#include <stdio.h>

/* Se fossem funcoes separadas nao haveria razao para usar ponteiros...
int paraKelvin(int C);
float paraFahrenheit(int C);
*/

// Funcao recebe uma entrada e devolve duas saidas
void converte(int, int*, float*);

int main() {
	int celsius;
	puts("Celsius\tKelvin\tFahrenheit");
	for (celsius = -30; celsius <= 50; ++celsius) {
		int kelvin;
		float fahrenheit;
		converte(celsius, &kelvin, &fahrenheit);
		printf("%d\t%d\t%.1f\n", celsius, kelvin, fahrenheit);
	}
	return 0;
}

void converte(int C, int* K, float* F) {
	*K = C + 273;
	*F = 9.0/5 * C + 32;	// divisao real!!!
}

