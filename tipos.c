#include <stdio.h>

int main() {
	char c1 = 65, c2 = -100;
	unsigned char c = c2;
	int i1 = 10, i2 = -10;
	unsigned int i = i2;
	float f = 3.1416;
	double d = 3.14159265354;
	_Bool b = 1; /* verdadeiro */

	printf("c1=%c c2=%c\n", c1, c2);
	printf("c1=%hhd c2=%hhd\n", c1, c2);
	printf("c1=%hhx c2=%hhx\n", c1, c2);
	printf("c=%c, c=%hhu, c=%hhx\n", c, c, c);
	printf("tamanho de c1/c2=%u\n", sizeof(c1));

	printf("i1=%d i2=%d\n", i1, i2);
	printf("i1=%x i2=%x\n", i1, i2);
	printf("i=%u, i=%x\n", i, i);
	printf("tamanho de i1/i2=%u\n", sizeof(i1));

	printf("f=%f\n", f);
	printf("f=%x\n", f);
	printf("tamanho de f=%u\n", sizeof(f));

	printf("d=%lf\n", d);
	printf("d=%llx\n", d);
	printf("tamanho de d=%u\n", sizeof(d));

	printf("b=%d\n", b);
	printf("tamanho de b=%u\n", sizeof(b));

	return 0;
}
