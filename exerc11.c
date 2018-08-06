#include <stdio.h>

int main() {
	int num;
	printf("Digite o numero a inverter: ");
	scanf("%d", &num);

	if (num != 0) {	// ou assim: if (num) { => if "verdadeiro"?
		float inv;	// variavel local ao bloco do if
		inv = 1 / (float)num;	// ou assim: inv = 1.0F / num;
		printf("O inverso eh %.3f.\n", inv);
	}
	else {
		printf("Erro: divisao por zero!\n");
	}
	return 0;
}

