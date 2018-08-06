#include <stdio.h>

int main() {
	int codigo;
	printf("Digite o codigo: ");
	scanf("%d", &codigo);

	switch (codigo) {
		case 1: printf("Alimento nao perecivel\n"); break;
		case 2: case 3: case 4: printf("Alimento perecivel\n"); break;
		case 5: case 6: printf("Vestuario\n"); break;
		case 7: printf("Higiene pessoal\n"); break;
		/*
		case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
		*/
		default:
			if (codigo >= 8 && codigo <= 15) {
				printf("Limpeza e utensilios domesticos\n");
			}
			else {
				printf("Invalido\n");
			}
	}
	return 0;
}

