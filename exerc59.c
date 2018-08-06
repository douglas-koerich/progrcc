#include <stdio.h>

// Prototipo (DECLARACAO) da funcao
unsigned absoluto(int);

int main() {
	printf("Digite um numero para testar: ");
	int v;
	scanf("%d", &v);

	/*
	// 1a. forma: mais completa
	unsigned w;
	w = absoluto(v);
	printf("Seu absoluto eh %u.\n", w);
	*/

	/*
	// 2a. forma: usando o retorno para inicializar
	unsigned w = absoluto(v);
	printf("Seu absoluto eh %u.\n", w);
	*/

	// 3a. forma: sem uma variavel intermediaria
	printf("Seu absoluto eh %u.\n", absoluto(v));

	return 0;
}

// DEFINICAO (conteudo do bloco) da funcao
unsigned absoluto(int num) {
	unsigned a;
	if (num >= 0) {
		a = num;
	}
	else {
		a = -num;
	}
	return a;
}

