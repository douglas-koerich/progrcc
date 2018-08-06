#include <stdio.h>

int main() {
	unsigned dependentes;
	float deducao;

	printf("Dependentes? ");
	scanf("%u", &dependentes);

	deducao = dependentes * 353.42;

	printf("A deducao com dependentes eh de R$ %.2f.\n", deducao);

	return 0;
}

