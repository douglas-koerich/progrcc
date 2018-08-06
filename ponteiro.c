#include <stdio.h>

int main() {
	int a = 65;		// variavel int convencional
	int* pi = &a;	// variavel-ponteiro para int (aponta p/)
	char *pc1 = NULL, *pc2, *pc3;

	// scanf("%p", &pi); (nao existe)
	// Atribuicao de um endereco VALIDO para um ponteiro
	pi = &a;	// & = 'o endereco de ...'

	// Uma atribuicao meio estranha...
	pc2 = &a;

	printf("O valor armazenado em pi eh %p\n", pi);
	printf("Os enderecos armazenados em pc1, pc2 e pc3 sao, respectivamente, %p, %p e %p\n", pc1, pc2, pc3);

	printf("O valor de a eh %d\n", a);
	printf("O valor de a eh %d\n", *pi);	// * = 'conteudo no endereco armazenado em ...'
	printf("O valor de a eh %c\n", *pc2);

	if (pc1 == NULL) {
		puts("Nao posso usar o ponteiro!");
	}
	else {
		printf("O valor apontado por pc1 eh %c\n", *pc1);
	}
	printf("O valor apontado por pc3 eh %c\n", *pc3);

	// Maus usos de ponteiro (erros, na maioria)
	/*
	pi = a;	// esqueci o &, mas ambos sao numeros!
	printf("%d\n", *pi);	// tentando imprimir o conteudo no endereco 65 (muito, mas muito mesmo, provavelmente invalido!)
	*/

	/* Compiladores mais recentes vao impedir a geracao desse codigo de maquina
	pi = *a;	// troquei o operador, mas como a tbem eh numero...
	printf("%d\n", *pi);
	*/

	return 0;
}

