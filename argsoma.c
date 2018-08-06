#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 3) {
		puts("Numero insuficiente de parcelas");
		printf("Digite: %s <valor-1> <valor-2>\n", argv[0]);
		return EXIT_FAILURE;
	}
	double x, y, soma;
	x = atof(argv[1]);
	y = atof(argv[2]);

	soma = x + y;
	printf("%lf\n", soma);

	return EXIT_SUCCESS;
}

