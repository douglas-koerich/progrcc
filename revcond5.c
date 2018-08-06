#include <stdio.h>

int main() {
	int idade;

	printf("Digite a idade [anos]: ");
	scanf("%d", &idade);

	/*
	if (idade >= 5 && idade <= 7)			printf("Infantil\n");
	else if (idade >= 8 && idade <= 10)		printf("Mirim\n");
	else if (idade >= 11 && idade <= 15)	printf("Juvenil\n");
	else if (idade >= 16 && idade <= 30)	printf("Adulto\n");
	else if (idade > 30)					printf("Senior\n");
	else									printf("INVALIDO\n");
	*/
	switch (idade) {
		case 5: case 6: case 7:
			printf("Infantil\n");
			break;

		case 8: case 9: case 10:
			printf("Mirim\n");
			break;

		case 11: case 12: case 13: case 14: case 15:
			printf("Juvenil\n");
			break;

		default:
			if (idade >= 16 && idade <= 30)	printf("Adulto\n");
			else if (idade > 30)			printf("Senior\n");
			else							printf("INVALIDO\n");
	}

	return 0;
}
