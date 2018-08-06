#include <stdio.h>
#include <math.h>

int eq2o_grau(int, int, int, double*, double*);

// Variaveis globais: raizes
// double x1, x2;	*** THIS IS EVIL!!! ***

int main(void) {
	int A, B, C;
	int resultado;	// variavel booleana
	double X1, X2;

	printf("Digite o coeficiente de grau 2 (A): ");
	scanf("%d", &A);
	printf("Digite o coeficiente de grau 1 (B): ");
	scanf("%d", &B);
	printf("Digite o coeficiente de grau 0 (C): ");
	scanf("%d", &C);

	resultado = eq2o_grau(A, B, C, &X1, &X2);

	if (resultado == 1) {
		puts("Existem raizes reais!");
		printf("x1 = %.2lf, x2 = %.2lf.\n", X1, X2);
	}
	else {
		puts("As raizes sao complexas!");
	}

	return 0;
}

int eq2o_grau(int a, int b, int c, double *r1, double *r2) {
	double delta;
	delta = pow(b, 2.0) - 4*a*c;
	if (delta < 0.0) {
		return 0;	// falso
	}
	else {
		*r1 = (-b + sqrt(delta))/(2*a);
		*r2 = (-b - sqrt(delta))/(2*a);
		return 1;	// verdadeiro
	}
}
