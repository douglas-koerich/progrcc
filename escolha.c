#include <stdio.h>

int main() {
	int num;

	printf("Digite um algarismo (0-9): ");
	scanf("%d", &num);

	/* Escada if-else
	if (num == 1) {
		...
	}
	else {
		if (num == 2) {
			...
		}
		else {
			if (num == 3) {
				...
			}
			else {
				...
			}
		}
	}
	*/

	switch (num) {
		case 1:
			printf("Um\n");
			break;

		case 2:
			printf("Dois\n");
			break;

		case 3:
			printf("Tres\n");
			break;

		default:
			printf("Outros\n");
	}

	return 0;
}

