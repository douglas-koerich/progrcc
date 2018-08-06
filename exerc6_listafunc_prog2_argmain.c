#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculaRaizes2o_Grau(float, float, float, float*, float*);

int main(int argc, char* argv[]) {
	float a, b, c, x1, x2;

	if (argc != 4) {	// nome do programa tambem conta
		puts("NUMERO INVALIDO DE PARAMETROS!");
		printf("Use: %s A B C, onde Ax^2 + Bx + C\n", argv[0]);
		return -1;
	}
	a = atof(argv[1]);
	b = atof(argv[2]);
	c = atof(argv[3]);
	if (!calculaRaizes2o_Grau(a, b, c, &x1, &x2)) {
		puts("Nao existem raizes reais!");
	}
	else {
		printf("As raizes sao %.2f e %.2f\n", x1, x2);
	}
	return 0;
}

int calculaRaizes2o_Grau(float A, float B, float C, float* X1, float* X2) {
	float delta;
	delta = B*B - 4*A*C;
	if (delta < 0) {
		return 0;	// retorna falso
	}
	*X1 = (-B + sqrt(delta))/(2*A);
	*X2 = (-B - sqrt(delta))/(2*A);
	return 1;
}

