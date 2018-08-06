#include <stdio.h>

int main() {
	int idade;
	printf("Digite a idade: ");
	scanf("%d", &idade);

	// Para casa: testar quando idade eh menor do que 5 anos...

	printf("Categoria ");
	if (idade >= 5 && idade <= 7) {
		printf("INFANTIL.\n");
	}
	else {	// nao eh infantil
		if (idade >= 8 && idade <= 10) {	// poderia ser if (idade <= 10)
			printf("MIRIM.\n");
		}
		else { // nao eh mirim (e ja nao era infantil)
			if (idade >= 11 && idade <= 15) {	// poderia ser idade <= 15
				printf("JUVENIL.\n");
			}
			else {
				if (idade >= 16 && idade <= 30) {
					printf("ADULTO.\n");
				}
				else {
					printf("SENIOR.\n");
				}
			}
		}
	}
	/*
	if (idade >= 5 && idade <= 7)
		printf("INFANTIL.\n");
	else if (idade >= 8 && idade <= 10)
		printf("MIRIM.\n");
	else if (idade >= 11 && idade <= 15)
		printf("JUVENIL.\n");
	else if (idade >= 16 && idade <= 30)
		printf("ADULTO.\n");
	else 
		printf("SENIOR.\n");
	*/
	return 0;
}

