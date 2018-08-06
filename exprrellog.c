#include <stdbool.h>
#include <stdio.h>

int main() {
	int a = 10, b = 20, c = 5, d = 0;
	bool teste;

	printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

	teste = a < b;
	printf("teste (a<b) = %d\n", teste);

	teste = a > b;
	printf("teste (a>b) = %d\n", teste);

	teste = a < b && c > d;
	printf("teste (a<b && c>d) = %d\n", teste);

	teste = a < b || c > d;
	printf("teste (a<b || c>d) = %d\n", teste);

	teste = a != b;
	printf("teste (a!=b) = %d\n", teste);

	teste = a == b;
	printf("teste (a==b) = %d\n", teste);

	return 0;
}

