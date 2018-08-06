#include <stdio.h>
#include <math.h>

int main() {
	int a = 26, x = 12;
	float b = 10;	// inicializacao

	/*
	int a, x;
	float b;

	a = 26;	// atribuicao
	x = 12;
	b = 10;
	*/

	int c;
	float d;

	c = a + x; printf("a+x = %d\n", c);
	c = a - x; printf("a-x = %d\n", c);
	c = a * x; printf("a*x = %d\n", c);
	c = a / x; printf("a/x = %d\n", c);
	c = a % x; printf("a%%x = %d\n", c);	// dois % para imprimir um % :-)

	printf("a/x com %%f = %f\n", a/x);
	printf("a/x com cast = %f\n", a/(float)x);	// cast

	d = a + b; printf("a+b = %f\n", d);
	d = a - b; printf("a-b = %f\n", d);
	d = a * b; printf("a*b = %f\n", d);
	d = a / b; printf("a/b = %f\n", d);

	printf("a/b (int) = %d\n", d);	// vai imprimir um numero estranho...

	d = a + b * x; printf("a+b*x=%f\n", d);
	d = (a + b) * x; printf("(a+b)*x=%f\n", d);

	int y = 9, z = 3;
	float w;

	w = pow(y, z); printf("y**z=%f\n", w);
	w = sqrt(y); printf("rad(y)=%f\n", w);
	w = exp(z);	printf("e**z=%f\n", w);
	w = log10(z); printf("log10(z)=%f\n", w);	

	return 0;
}

