#include <stdio.h>

int somaInternos(float, float);

int main() {
	float x, y;
	printf("Digite inicial: "); scanf("%f", &x);
	printf("Digite final: "); scanf("%f", &y);

	printf("Soma dos inteiros internos = %d\n", somaInternos(x, y));
	return 0;
}

int somaInternos(float inicial, float final) {
	int soma = 0;
	int ini = inicial;	// trunca o valor real (soh parte inteira)
	int fin = final; // idem
	int n;

	ini = ini+1;	// primeiro inteiro DEPOIS do inicial
					// ex: se inicial=3.0, ini=3 -> ini=4
					//     se inicial=3.8, ini=3 -> ini=4
	if (fin == final) fin = fin - 1;	// ultimo inteiro ANTES do final
										// ex: se final=6.0, fin=6 -> fin=5
										//     se final=6.2, fin=6 -> fin=6
	for (n=ini; n<=fin; ++n) {
		soma += n;
	}
	return soma;
}

