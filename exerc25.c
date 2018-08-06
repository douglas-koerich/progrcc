#include <stdio.h>

int main() {
	float a, b, c;

	printf("Digite a: "); scanf("%f", &a);
	printf("Digite b: "); scanf("%f", &b);
	printf("Digite c: "); scanf("%f", &c);

	if (a >= b+c || b >= a+c || c >= a+b) {
		printf("Os valores nao formam um triangulo.\n");
	}
	else {
		if (a == b && b == c /*&& a == c*/) {
			printf("Eh um triangulo equilatero.\n");
		}
		else {
			if (a != b && b != c && a != c) {
				printf("Eh um triangulo escaleno.\n");
			}
			else {
				// Por exclusao...
				printf("Eh um triangulo isosceles.\n");
			}
		}
	}
	return 0;
}
