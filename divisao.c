#include <stdio.h>

int main() {
	int a, b, c = -1;

	printf("Digite a: "); scanf("%d", &a);
	printf("Digite b: "); scanf("%d", &b);

	if (b != 0) {
		c = a / b;
		printf("c = %d\n", c);
	}
	else {
		printf("b invalido (nulo)!\n");
	}
	return 0;
}

