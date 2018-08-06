#include <stdio.h>

int main() {
	int N, D;

	printf("Lados? ");
	scanf("%d", &N);

	D = N * (N - 3) / 2;

	printf("Diagonais: %d\n", D);

	return 0;
}

