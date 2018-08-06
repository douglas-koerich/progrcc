#include <stdio.h>
#include <math.h>

int main() {
	float x, erro;

	do {
		printf("Digite x: ");
		scanf("%f", &x);
	} while (fabs(x) >= 1.0);	// while (x <= -1.0 || x >= 1.0);

	printf("Digite o erro: ");
	scanf("%f", &erro);

	// Calcula o valor de f(x) pela funcao de referencia
	float f_original = 1/(1-x);

	// Laco para alcancar o valor original pela funcao f(x) de aproximacao
	float f_aproximado = 0;
	int num_termos = 0;
	do {
		f_aproximado += pow(x, num_termos++);
	} while (fabs(f_original-f_aproximado) >= erro);

	printf("O numero de termos necessarios foi %d (f_original=%f, f_aproximado=%f)\n",
		num_termos, f_original, f_aproximado);

	return 0;
}

