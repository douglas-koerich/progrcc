#include <stdio.h>

int main() {
	int num;
	printf("Digite o numero: ");
	scanf("%d", &num);

	if (num % 3 == 0) {
		// O numero eh divisivel por 3
		if (num % 5 == 0) {
			printf("O numero eh divisivel por 3 e por 5\n");
		}
		else {
			printf("O numero eh divisivel somente por 3\n");
		}
	}
	else {
		// O numero NAO eh divisivel por 3
		if (num % 5 == 0) {
			printf("O numero eh divisivel somente por 5\n");
		}
		else {
			printf("O numero nao eh divisivel por 3 nem por 5\n");
		}
	}

	/* Pratica ruim de programacao: escada if-else sem chaves e correta indentacao
	if (num % 3 == 0)
		if (num % 5 == 0) printf("O numero eh divisivel por 3 e por 5\n");
		else printf("O numero eh divisivel somente por 3\n");
	else
		if (num % 5 == 0) printf("O numero eh divisivel somente por 5\n");
		else printf("O numero nao eh divisivel por 3 nem por 5\n");
	*/
	return 0;
}

