#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// float r1, r2;	* Global variables are EVIL hahahaha *

bool calcula2o_grau(int a, int b, int c, float* x1, float* x2) {
	float delta = b*b - 4*a*c;
	if (delta < 0) {
		return false;
	}
	printf("*Antes do calculo: %f e %f.\n", *x1, *x2);
	*x1 = (-b + sqrt(delta)) / (2*a);
	*x2 = (-b - sqrt(delta)) / (2*a);
	printf("*Depois do calculo: %f e %f.\n", *x1, *x2);
	return true;
}

int main(void) {
	int A, B, C;
	float r1, r2;
	puts("Digite os coeficientes da expressao do 2o. grau:");
	printf("A (coef. grau 2)? ");
	scanf("%d", &A);
	printf("B (coef. grau 1)? ");
	scanf("%d", &B);
	printf("C (coef. grau 0)? ");
	scanf("%d", &C);

	bool raizes_existem = calcula2o_grau(A, B, C, &r1, &r2);

	if (raizes_existem == true) {
		printf("As raizes existem e sao %f e %f.\n", r1, r2);
	}
	else {
		puts("Nao existem raizes reais.");
	}
	return 0;
}

