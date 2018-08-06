#include <stdio.h>

int main() {
	char sexo;
	int idade, anos_trabalhados, resto_idade, resto_trabalho;

	printf("Digite o sexo do contribuinte do INSS: ");
	scanf(" %c", &sexo);
	printf("Qual a idade? ");
	scanf("%d", &idade);
	printf("Quantos anos de trabalho? ");
	scanf("%d", &anos_trabalhados);

	switch (sexo) {
		case 'f':
		case 'F':
			resto_idade = 60 - idade;
			resto_trabalho = 30 - anos_trabalhados;
			break;

		case 'm':
		case 'M':
			resto_idade = 65 - idade;
			resto_trabalho = 35 - anos_trabalhados;
			break;

		default:	// outros (LGBT)
			printf("Este programa eh homofobico...\n");
			return -1;	// sai do programa com valor de retorno indicando erro
	}
	if (resto_idade <= 0 || resto_trabalho <= 0) {
		printf("Ja pode se aposentar!\n");
	}
	else {
		/*
		if (resto_idade > resto_trabalho) {
			printf("Restam %d anos para se aposentar.\n", resto_trabalho);
		}
		else {
			printf("Restam %d anos para se aposentar.\n", resto_idade);
		}
		*/
		printf("Restam %d anos para se aposentar.\n", resto_idade>resto_trabalho? resto_trabalho: resto_idade);
	}
	return 0;
}

