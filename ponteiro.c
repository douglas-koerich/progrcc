#include <stdio.h>

void troca(int* a, int* b) {
	int c = *a;	// o conteudo no endereco guardado em a (a=&x) eh salvo
	*a = *b;	// o conteudo no endereco guardado em b (&y) vai para x (*a)
	*b = c;		// o conteudo de y (*b) recebe o valor salvo
}

int main() {
	int x, y;

	printf("Digite o valor de x: ");
	scanf("%d", &x);

	printf("Digite o valor de y: ");
	scanf("%d", &y);

	printf("Antes da troca: x=%d, y=%d.\n", x, y);

	troca(&x, &y);	// passa os enderecos pra 'troca' poder alterar!

	printf("Depois da troca: x=%d, y=%d.\n", x, y);

	return 0;
}

