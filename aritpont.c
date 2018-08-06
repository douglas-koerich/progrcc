#include <stdio.h>

#define MAX 10

int main() {
	//char vetor[MAX] = { 'a', 'e', 'i', 'o', 'u' };
	//char* c = &vetor[0];
	int vetor[MAX] = { 1, 2, 3, 4, 5 };
	int* c = &vetor[0];

	printf("O vetor inicia na posicao %p da memoria com o valor %d.\n", c, *c);

	//char* b = c + 1;
	int* b = c + 1;	// +1 nao eh absoluto, eh um +1 relativo ao tamanho do tipo
	printf("O ponteiro b tem o valor/endereco %p e nesse endereco o caractere eh %d.\n", b, *b);

	++b;
	printf("Agora, o ponteiro b eh %p e nesse endereco o caractere eh %d.\n", b, *b);

	return 0;
}

