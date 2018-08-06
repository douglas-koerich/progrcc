#include <stdio.h>

int main() {
	int num;

	printf("Digite o numero: ");
	scanf("%d", &num);

	if (num % 3 == 0 && num % 5 == 0) {
		printf("O numero eh divisivel por 3 e por 5\n");
	}
	else {
		printf("O numero nao eh divisivel por 3 e por 5 simultaneamente\n");
	}
	return 0;
}

